#ifndef ENGINE
#define ENGINE

typedef struct vec
{
    float x;
    float y;
} Vector;

class Engine
{
public:
    Engine();
    virtual ~Engine();

    void updateCoordinates();
    Vector getCoordinates(int id);

protected:
    Vector position[3];
    Vector velocity[3];
    float mass[3];
    float G;
    float delta;
    int steps_per_frame;

    // calculates net acceleration for obj i
    Vector F(int i);
    void calculateStep();
};

#endif