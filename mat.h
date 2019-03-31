#ifndef MAT_H
#define MAT_H
class Mat
{
public:
    Mat();
    void Kv(int pole); // sqv in pole
    void Simple(long numb); //simple numb
    void Kr1N1(int numb, int pole); //разрешимость сравнения x^2=numb mod pole
private: int rez=1;
};
#endif // MAT_H
