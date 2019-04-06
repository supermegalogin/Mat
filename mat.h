#ifndef MAT_H
#define MAT_H
class Mat
{
public:
    Mat();
    void Kv(int pole); // вычисление квадрата числа в поле
    int* Simple(long numb); //разложение числ на простые множетели (далеко от совершенства)
    int symbLegendre(long numb, int pole); //Символ Лежандра (разрешимость сравнения x^2=numb mod pole)
    int symbLegendre2(int numb, int pole);// без разложения на простые множетели => работает со всеми числами
    void lemmaGausa(int numb, int pole); //Символ Лежандра по лемме Гаусса
    void symbJacobi(long numb, int pole); //Символ Якоби (произведение символов Лежандра)
    void fastPower(long numb, int pole);
private: int rez=1, size=0;
};
#endif // MAT_H
