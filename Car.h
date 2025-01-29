#include <cmath>

class Car
{
    float _positionX = 0.0f, _positionY = 0.0f;
    float _speed = 0.0f;
    float _angle = 0.0f;
    const float Acceleration = 0.1f;
    const float Deceleration = 0.005f;
    const float MaxSpeed = 0.1f;
    const float TurnSpeed = 2.0f;
    const float DegreesToRadians = 3.14159 / 180.0;

public:
    Car() {};
    Car(float x, float y) : _positionX(x), _positionY(y) {};

    void updatePosition()
    {
        _positionX += _speed * std::cos(_angle * DegreesToRadians);
        _positionY += _speed * std::sin(_angle * DegreesToRadians);
    }

    void accelerate()
    {
        if (_speed < MaxSpeed)
        {
            _speed += Acceleration;
        }
    }

    void brake()
    {
        if (_speed > 0.0f)
        {
            _speed -= Deceleration;
        }
    }

    void turnLeft()
    {
        _angle += TurnSpeed;
    }

    void turnRight()
    {
        _angle -= TurnSpeed;
    }

    float getPositionX() const { return _positionX; }
    float getPositionY() const { return _positionY; }
    float getSpeed() const { return _speed; }
    float getAngle() const { return _angle; }
};
