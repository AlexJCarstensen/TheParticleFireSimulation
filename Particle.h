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
            _xSpeed = 0.001 *((( 2.0 * rand())/RAND_MAX) -1);
            _ySpeed = 0.001 *((( 2.0 * rand())/RAND_MAX)- 1);
        }
        virtual ~Particle(){}
        void update() {

            _x += _xSpeed;
            _y += _ySpeed;

            if(_x <= -1.0 || _x >= 1.0)
                _xSpeed = -_xSpeed;
            if(_y <= -1.0 || _y >= 1.0)
                _ySpeed = -_ySpeed;
        }
        void setX(double x){_x = x;}
        void setY(double y){_y = y;}
        double getX() const{return _x;}
        double getY() const{return _y;}

    private:
        double _x;
        double _y;
        double _xSpeed;
        double _ySpeed;
    };

}
#endif //THEPARTICLEFIRESIMULATION_PARTICLE_H
