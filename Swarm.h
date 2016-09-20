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
        Swarm(){_particles = new Particle[NParticles];}
        virtual ~Swarm(){delete [] _particles;}

        const Particle* const getParticles(){ return _particles;}

    private:
        Particle* _particles;
    };

}
#endif //THEPARTICLEFIRESIMULATION_SWARM_H
