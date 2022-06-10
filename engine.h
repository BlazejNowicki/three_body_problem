#ifndef ENGINE
#define ENGINE

#include <vector>

typedef struct vec {
    float x;
    float y;
} Vector;

class Engine {
public:
    Engine(std::vector <Vector> position,
           std::vector <Vector> velocity,
           std::vector<float> mass,
           float G,
           float delta,
           int steps_per_frame);

    virtual ~Engine();

    void updateCoordinates();

    Vector getCoordinates(int id);

protected:
    std::vector <Vector> position;
    std::vector <Vector> velocity;
    std::vector<float> mass;
    float G;
    float delta;
    int steps_per_frame;

    // calculates net acceleration for obj i
    Vector F(int i);

    void calculateStep();
};

#endif