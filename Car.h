#include <cmath>
#include <SFML/Graphics.hpp>

class Car
{
    float _positionX = 0.0f, _positionY = 0.0f;
    float _speed = 0.0f;
    float _angle = 0.0f;
    float _deltaTime = 0.0f;
    const float Acceleration = 0.1f;
    const float Deceleration = 0.005f;
    const float MaxSpeed = 0.1f;
    const float TurnSpeed = 2.0f;
    const double DegreesToRadians = 3.14159 / 180.0;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Keyboard::Key _pressedKey = sf::Keyboard::Key::Unknown;

public:
    Car() {};
    Car(float x, float y) : _positionX(x), _positionY(y)
    {
        if (!_texture.loadFromFile("MainCar.png"))
        {
            throw std::runtime_error("Cannot load MainCar.png");
        }

        _sprite.setTexture(_texture);
        int xPosition = _texture.getSize().x / 2.0f;
        int yPosition = _texture.getSize().y / 2.0f;

        _sprite.setOrigin(xPosition, yPosition);
        _sprite.setPosition(_positionX, _positionY);
    };

    void update()
    {
        switch (_pressedKey)
        {
            case sf::Keyboard::Up:
                accelerate();
                break;
            case sf::Keyboard::Down:
                brake();
                break;
            case sf::Keyboard::Left:
                turnLeft();
                break;
            case sf::Keyboard::Right:
                turnRight();
                break;
        }

        updatePosition();
        updateSpritePosition();
    }
    
    void draw(sf::RenderWindow& window)
    {
        window.draw(_sprite);
    }

    void updatePosition()
    {
        _positionX += _speed * std::cos(_angle * DegreesToRadians);
        _positionY += _speed * std::sin(_angle * DegreesToRadians);
    }

    void updateSpritePosition()
    {
        _sprite.setPosition(_positionX, _positionY);
        _sprite.setRotation(_angle);
    }

    void accelerate()
    {
        if (_speed < MaxSpeed)
        {
            _speed += Acceleration * _deltaTime;
        }
    }

    void brake()
    {
        if (_speed > 0.0f)
        {
            _speed -= Deceleration * _deltaTime;
        }
    }

    void turnLeft()
    {
        _angle += TurnSpeed * _deltaTime;
    }

    void turnRight()
    {
        _angle -= TurnSpeed * _deltaTime;
    }

    void setPressedKey(sf::Keyboard::Key pressedKey)
    {
        _pressedKey = pressedKey;
    }

    void setDeltaTime(float deltaTime)
    {
        _deltaTime = deltaTime;
    }

    void setTextureSize(const sf::Vector2u& windowSize)
    {
        sf::Vector2u textureSize = _texture.getSize();
        float scale = std::min((windowSize.x * 0.1f) / textureSize.x, (windowSize.y * 0.1f) / textureSize.y);
        _sprite.setScale(scale, scale);
    }

    float getPositionX() const { return _positionX; }
    float getPositionY() const { return _positionY; }
    float getSpeed() const { return _speed; }
    float getAngle() const { return _angle; }
};
