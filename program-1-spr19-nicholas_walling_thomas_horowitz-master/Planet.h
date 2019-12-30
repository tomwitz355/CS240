#ifndef DEF_VAR_PLANET
#define DEF_VAR_PLANET

class Planet{
	private:
		int pos;
		int distance;
		char type;
	public:
	Planet(int);
       	int orbit();
	long getID(){return (long)this;}
        int getDistance(){return this->distance;}
        int getPos(){return this->pos;}
	char getType(){ return this->type;}
		//you may add any additional methods you may need.
};



#endif
