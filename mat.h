#ifndef MAT_H
#define MAT_H
class Mat
{
public:
    Mat();
    void Kv(int pole); // вычисление квадрата числа в поле
    int* Simple(long numb); //разложение числ на простые множетели
    void symbLegendre(long numb, int pole); //Символ Лежандра (разрешимость сравнения x^2=numb mod pole)
    void lemmaGausa(int numb, int pole); //Символ Лежандра по лемме Гаусса
private: int rez=1, size=0;
};
#endif // MAT_H
