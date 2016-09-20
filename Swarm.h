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
        const static int NParticles = 50000;

    public:
        Swarm(): lastTime(0)
        {_particles = new Particle[NParticles];}
        virtual ~Swarm(){delete [] _particles;}

        void update(int elapsed)
        {
            int interval = elapsed - lastTime;

            for (int i = 0; i < Swarm::NParticles; i++)
            {
                _particles[i].update(interval);
            }

            lastTime = elapsed;
        }

        const Particle* const getParticles(){ return _particles;}

    private:
        Particle* _particles;
        int lastTime;
    };

}
#endif //THEPARTICLEFIRESIMULATION_SWARM_H
