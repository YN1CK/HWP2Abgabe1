#ifndef POSITION_H
#define POSITION_H

typedef struct {
	int x;
	int y;
	int z;
} koordinaten;

class position {
public:
	void setPosition(int x, int y, int z);
	koordinaten getPosition();

private:
	koordinaten aktuellPosition;
};

#endif//POSITION_H
