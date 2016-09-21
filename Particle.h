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
        Particle() : x_(0), y_(0)
        {
            angle_ = (2 * M_PI * (rand()) / RAND_MAX);
            speed_ = (0.0001 * rand())/RAND_MAX; 
        }

        virtual ~Particle()
        {}

        void update(int interval)
        {
            x_ += speed_ * cos(angle_) * interval;
            y_ += speed_ * sin(angle_) * interval;
        }

        double getX() const
        { return x_; }

        double getY() const
        { return y_; }

    private:
        double x_;
        double y_;
        double speed_;
        double angle_;
    };

}
#endif //THEPARTICLEFIRESIMULATION_PARTICLE_H
