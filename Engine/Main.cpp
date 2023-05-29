#include "Graphic.h"
#include "Random.h"
#include "../Tests/Test.h"
#include "../Tests/ParticleTest.h"
#include "../Tests/ForceTest.h"
#include "../Tests/JointTest.h"
#include "../Tests/CollisionTest.h"
#include <SDL.h>
#include<glm/glm.hpp>
#include<iostream>

int main(int argc, char* argv[])
{
    Test* test = new JointTest;
    test->Initialize();

    while (!test->IsQuit())
    {
        test->Run();
    }
    delete test;

    return 0;
}