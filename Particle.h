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
            init();
        }

        virtual ~Particle()
        {}


        void update(int interval)
        {
            angle_ += interval*0.0003;

            x_ += speed_ * cos(angle_) * interval;
            y_ += speed_ * sin(angle_) * interval;
            if(x_ < -1 || x_ > 1 || y_ < -1 || y_ > 1)
            {
                init();
            }
            if(rand() < RAND_MAX/100)
            {
                init();
            }
        }

        double getX() const
        { return x_; }

        double getY() const
        { return y_; }

    private:
        void init()
        {
            x_ = 0;
            y_ = 0;
            angle_ = (2 * M_PI * rand()) / RAND_MAX;
            speed_ = (0.04* rand())/RAND_MAX;

            speed_ *= speed_;
        }
    private:
        double x_;
        double y_;
        double speed_;
        double angle_;
    };

}
#endif //THEPARTICLEFIRESIMULATION_PARTICLE_H
