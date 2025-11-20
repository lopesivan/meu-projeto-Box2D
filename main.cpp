#include <box2d/box2d.h>
#include <iostream>

int main()
{
    // mundo com gravidade -10 m/s²
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    // chão estático
    b2BodyDef groundDef;
    groundDef.position.Set(0.0f, -10.0f);
    b2Body* ground = world.CreateBody(&groundDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 1.0f);
    ground->CreateFixture(&groundBox, 0.0f);

    // caixa dinâmica
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 20.0f);
    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    // simula 2 s em passos de 60 Hz
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 120; ++i) {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 pos = body->GetPosition();
        float angle = body->GetAngle();
        std::printf("%4.2f s  ->  pos=(%6.2f, %6.2f)  angle=%6.2f rad\n",
                    i * timeStep, pos.x, pos.y, angle);
    }
    return 0;
}
