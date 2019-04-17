#ifndef MAT_H
#define MAT_H
class Mat
{
public:
    Mat();
    ~Mat();
    void Kv(int pole); // вычисление квадрата числа в поле
    int* Simple(long numb); //разложение числ на простые множетели (далеко от совершенства)
    int symbLegendre(long numb, int pole); //Символ Лежандра (разрешимость сравнения x^2=numb mod pole)
    int symbLegendre2(int numb, int pole);// без разложения на простые множетели => работает со всеми числами
    void lemmaGausa(int numb, int pole); //Символ Лежандра по лемме Гаусса
    void symbJacobi(long numb, int pole); //Символ Якоби (произведение символов Лежандра)
    void fastPower(long numb,int pow, int pole);// возведение целого числа в степень в поле
    void fastPower2(int numb,int pow, int pole);// возведение целого числа в степень в поле (лучше)
    void ellCorPoint(int a,int b,int c, int pole); //y^2=ax^3+bx+c нахождение точек эллиптической кривой
    int Nod(int a, int b);// Нод a и b по алгоритму Евклида
    void Diof(int a, int b);// решение диофантова уравнения ax+by=1 ( для a и b взаимнопростых)
private: int rez=1, size=0;
};
#endif // MAT_H
