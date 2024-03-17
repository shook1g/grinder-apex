#pragma once
//==============-------[RESOLVER]------==============================
class Resolver {
public:
    static QAngle CalculateAngle(FloatVector3D from, FloatVector3D to) {
        FloatVector3D newDirection = to.subtract(from);
        newDirection.normalize();
        
        float pitch = -asinf(newDirection.z) * (180 / M_PI);
        float yaw = atan2f(newDirection.y, newDirection.x) * (180 / M_PI);

        return QAngle(pitch, yaw);
    }

    static FloatVector3D GetTargetPosition(const FloatVector3D& targetPosition, FloatVector3D targetVelocity, float time) {
        return targetPosition.subtract((targetVelocity.multiply(time)));
    }

    static float GetTimeToTarget(FloatVector3D startPosition, FloatVector3D endPosition, float bulletSpeed) {
        float distance = (endPosition.subtract(startPosition)).magnitude();
        return distance / bulletSpeed;
    }

    static float GetBasicBulletDrop(FloatVector3D startPosition, FloatVector3D endPosition, float bulletSpeed, float bulletDropRate) {
        float time = GetTimeToTarget(startPosition, endPosition, bulletSpeed);
        bulletDropRate *= 750.0f;
        return 0.5f * bulletDropRate * time * time;
    }

    static FloatVector3D GetTargetPosition(FloatVector3D startPosition, FloatVector3D endPosition, FloatVector3D targetVelocity, float bulletSpeed) {
        float time = GetTimeToTarget(startPosition, endPosition, bulletSpeed);
        return GetTargetPosition(endPosition, targetVelocity, bulletSpeed);
    }

    // Aim at moving target without bullet drop predicion
    static bool CalculateAimRotation(FloatVector3D startPosition, FloatVector3D endPosition, FloatVector3D targetVelocity, float bulletSpeed, QAngle& result) {
        endPosition = GetTargetPosition(startPosition, endPosition, targetVelocity, bulletSpeed);
        result = CalculateAngle(startPosition, endPosition);
        return true;
    }

    // Aim at moving target without movement prediction
    static void CalculateAimRotationBasicDrop(FloatVector3D startPosition, FloatVector3D endPosition, FloatVector3D targetVelocity, float bulletSpeed, float bulletScale, QAngle& result) {
        endPosition.z += GetBasicBulletDrop(startPosition, endPosition, bulletSpeed, bulletScale);
        result = CalculateAngle(startPosition, endPosition);
    }

    static bool CalculateAimRotationNew(FloatVector3D start, FloatVector3D targetPosition, FloatVector3D targetVelocity, float bulletSpeed, float bulletScale, int steps, QAngle& result) {
        const float gravity = 750.0f / bulletScale;

        float angle = 0;
        float time = 0.0;
        float timeStep = 1.0f / steps;

        for(int i = 0; i < steps; i++) {
            FloatVector3D predictedPosition = GetTargetPosition(targetPosition, targetVelocity, time);
            if (!OptimalAngle(start, predictedPosition, bulletSpeed, gravity, angle))
                continue;
            
            FloatVector3D direction = predictedPosition.subtract(start);
            float horizontalDistance = direction.magnitude2D();
            float travelTime = horizontalDistance / (bulletSpeed * cosf(angle));

            if(travelTime <= time){
                result.x = -angle  * (180 / M_PI);
                result.y = atan2f(direction.y, direction.x)  * (180 / M_PI);
                return true;
            }
            time += timeStep;
        }

        targetPosition = GetTargetPosition(start, targetPosition, targetVelocity, bulletSpeed);
        result = CalculateAngle(start, targetPosition);
        return true;
    }

    static float GetTimeToTarget(const FloatVector3D start, const FloatVector3D end, const float speed, const float gravity) {
        float horizontalDistance = start.distance2D(end);
        float heightDifference = end.z - start.z;
        return (speed * sqrtf(2 * sinf(M_PI / 4) / gravity)) + (sqrtf(2 * sinf(M_PI / 4) * (sinf(M_PI / 4) - 2 * heightDifference) / gravity));
    }

    static bool OptimalAngle(const FloatVector3D start, const FloatVector3D end, const float speed, const float gravity, float& angle) {
        float horizontalDistance = start.distance2D(end);
        float heightDifference = end.z - start.z;
        
        float root = powf(speed, 4) - gravity * (gravity * powf(horizontalDistance, 2) + 2 * heightDifference * powf(speed, 2));
        if (root < 0.0)
            return false;

        float term1 = powf(speed, 2) - sqrt(root);
        float term2 = gravity * horizontalDistance;

        angle = atanf(term1 / term2);
        return true;
    }
};
