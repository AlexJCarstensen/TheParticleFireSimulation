//
// Created by plex on 9/20/16.
//

#ifndef THEPARTICLEFIRESIMULATION_PARTICLE_H
#define THEPARTICLEFIRESIMULATION_PARTICLE_H

#include <cstdlib>

namespace ParticleFireSimulation
{

    class Particle
    {
    public:
        Particle(){
            _x = ((2.0 * rand())/RAND_MAX) -1;
            _y = ((2.0 * rand())/RAND_MAX) -1;
        }
        virtual ~Particle(){}
        void setX(double x){_x = x;}
        void setY(double y){_y = y;}
        double getX() const{return _x;}
        double getY() const{return _y;}

    private:
        double _x;
        double _y;
    };

}
#endif //THEPARTICLEFIRESIMULATION_PARTICLE_H
