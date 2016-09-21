//
// Created by plex on 9/20/16.
//

#ifndef THEPARTICLEFIRESIMULATION_SWARM_H
#define THEPARTICLEFIRESIMULATION_SWARM_H

#include "Particle.h"

namespace ParticleFireSimulation
{
    class Swarm
    {
    public:
        const static int NParticles = 5000;

    public:
        Swarm(): lastTime_(0)
        {particles_ = new Particle[NParticles];}
        virtual ~Swarm(){delete [] particles_;}

        void update(int elapsed)
        {
            int interval = elapsed - lastTime_;

            for (int i = 0; i < Swarm::NParticles; i++)
            {
                particles_[i].update(interval);
            }

            lastTime_ = elapsed;
        }

        const Particle* const getParticles(){ return particles_;}

    private:
        Particle* particles_;
        int lastTime_;
    };

}
#endif //THEPARTICLEFIRESIMULATION_SWARM_H
