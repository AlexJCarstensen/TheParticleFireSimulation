//
// Created by plex on 9/20/16.
//

#ifndef THEPARTICLEFIRESIMULATION_PARTICLE_H
#define THEPARTICLEFIRESIMULATION_PARTICLE_H

#include <cstdlib>
#include <math.h>

namespace ParticleFireSimulation
{

    class Particle
    {
    public:
        Particle() : _x(0), _y(0)
        {
            _angle = (2 * M_PI * (rand()) / RAND_MAX);
            _speed = (0.001 * rand())/RAND_MAX;
        }

        virtual ~Particle()
        {}

        void update()
        {
            _x += _speed * cos(_angle);
            _y += _speed * sin(_angle);
        }

        void setX(double x)
        { _x = x; }

        void setY(double y)
        { _y = y; }

        double getX() const
        { return _x; }

        double getY() const
        { return _y; }

    private:
        double _x;
        double _y;
        double _speed;
        double _angle;
    };

}
#endif //THEPARTICLEFIRESIMULATION_PARTICLE_H
