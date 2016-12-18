#include <bits/stdc++.h>
using namespace std;

// Definiciones iniciales
typedef long long Coord;

const double ERROR = 1e-9;
const double M_2PI = 2 * M_PI;

// Tolerancia en flotantes
bool Igual(Coord a, Coord b) { 
    return fabs(a - b) < ERROR;
}

// Punto en 2D
struct Punto {
    Coord x, y;

    Punto() : x(0), y(0) {}
    Punto(Coord x_, Coord y_)
        : x(x_), y(y_) {}

    // Izquierda a derecha, abajo a arriba
    bool operator<(const Punto& cmp) const {
        if (!Igual(x, cmp.x)) return x < cmp.x;
        return Igual(y, cmp.y)? false: y < cmp.y;
    }
 
    bool operator==(const Punto& cmp) const {
        return Igual(x, cmp.x) && Igual(y, cmp.y);
    } 
};

// Puntos: p, q
// Vectores: v, w

// Distancia entre dos puntos p y q
double Distancia(const Punto& p, const Punto& q) {
    return hypot(p.x - q.x, p.y - q.y);
}

// Magnitud de un vector v
double Magnitud(const Punto& v) {
    return hypot(v.x, v.y);
}

// Producto punto entre vectores v y w
double Dot(const Punto& v, const Punto& w) {
    return v.x * w.x + v.y * w.y;
}

// Producto cruz entre vectores v y w
double Cruz(const Punto& v, const Punto& w) {
    return v.x * w.y - v.y * w.x;
}

// Conversion de grados a radianes
double GradARad(double grd) {
    return (grd * M_PI) / 180;
}

// Conversion de radianes a grados
double RadAGrad(double rad) {
    return (rad * 180) / M_PI;
}

// Rotar un punto respecto al origen
// La rotación se hace en orden CCW, para
// rotar en CW llamar Rotar(p, M_2PI - rad)
Punto Rotar(const Punto& p, double rad) {
    return Punto(p.x*cos(rad) - p.y*sin(rad),
                 p.x*sin(rad) + p.y*cos(rad));
}

// Trasladar p tomando como origen al punto o 
Punto Trasladar(const Punto& o, const Punto& p) {
    return Punto(p.x - o.x, p.y - o.y);
}

// Escalar un vector v por un factor s
Punto Escalar(const Punto& v, double s) {
    return Punto(v.x * s, v.y * s);
}

// Obtener vector opuesto
Punto Opuesto(const Punto& v) {
    return Punto(-v.x, -v.y);
}

// Angulo entre vectores v y w
double Angulo(const Punto& v, const Punto& w) {
    return acos(Dot(v, w) / (Magnitud(v) * Magnitud(w)));
}

// Test de mano derecha: CCW = 1, CW = -1, Colineal = 0
int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
    double ccw = Cruz(Trasladar(o, p), Trasladar(o, q));
    return Igual(ccw, 0)? 0: (ccw < 0)? -1: 1;
}

// Linea en 2D
// Si los puntos no aseguran coordenadas
// enteras usar version double. ¡Cuidado!
// Verifiquense tags <comment> <uncomment>
struct Linea {
    Punto p, q;
    long long a, b, c; // <comment/>
    //double a, b, c; // <uncomment/>

    Linea() : p(), q(), a(0), b(0), c(0) {}

    Linea(Coord a_, Coord b_, Coord c_)
        : p(), q(), a(a_), b(b_), c(c_) {
        // <comment>
        c_ = abs(__gcd(a, b));
        a /= c_, b /= c_;
        // </comment>
    }

    Linea(const Punto& p_, const Punto& q_)
        : p(p_), q(q_), a(), b(), c() {
        // Asegura p como punto menor
        if (q < p) swap(p, q);
        a = q.y - p.y;
        b = p.x - q.x;
        if (!a) c = p.y, b = -1;
        else if (!b) c = p.x, a = -1;
        else {
            // <comment>
            c = abs(__gcd(a, b));
            a /= c, b /= c;
            // </comment>
            c = -a*p.x - b*p.y;
        }
    }

    // ¡Peligro! Ordena por ecuacion de recta
    bool operator<(const Linea& cmp) const {
        if (!Igual(a, cmp.a)) return a < cmp.a;
        if (!Igual(b, cmp.b)) return b < cmp.b;
        return Igual(c, cmp.c)? false: c < cmp.c;
    }
};

// Rectas: r, s
// Segmentos: s, t

// Saber si un punto p esta en la recta r
bool PuntoEnRecta(const Punto& p, const Linea& r) {
    return !ManoDerecha(r.p, r.q, p);
}

// Saber si un punto o esta en el segmento s
bool PuntoEnSegmento(const Punto& p, const Linea& s) {
    return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}

// Saber si dos lineas son paralelas
bool LineasParalelas(const Linea& l, const Linea& m) {
    return l.a == m.a && l.b == m.b; // <comment/>
    // <uncomment>
    //if (Igual(l.b, 0) || Igual(m.b, 0))
    //    return Igual(l.a, m.a) && Igual(l.b, m.b); 
    //return Igual(l.a/l.b, m.a/m.b);
    // </uncomment>
}

// Saber si dos lineas son iguales
bool LineasIguales(const Linea& l, const Linea& m) {
    return LineasParalelas(l, m) && Igual(l.c, m.c);
}

// Saber si dos lineas son perpendiculares
bool LineasPerpendiculares(const Linea& l, const Linea& m) {
    return (l.a == m.b && l.b == -m.a) ||
           (m.a == l.b && m.b == -l.a); // <comment/>
    // <uncomment>
    //if (Igual(l.b, 0) || Igual(l.a, 0))
    //    return Igual(l.a, m.b) && Igual(l.b, m.a);
    //return Igual(-l.a/l.b, m.b/m.a);
    // </uncomment>
}

// Obtener una linea paralela a l que pase por p
Linea ParalelaEnPunto(const Linea& l, const Punto& p) {
    return Linea(p, Punto(p.x - l.b, p.y + l.a));
}

// Obtener una linea perpendicular a l que pase por p
Linea PerpendicularEnPunto(const Linea& l, const Punto& p) {
    return Linea(p, Punto(p.x + l.a, p.y + l.b));
}

// Saber si dos rectas r y s se intersectan
bool InterseccionRectas(const Linea& r, const Linea& s) {
    return !LineasParalelas(r, s);
}

// Saber si una recta r y un segmento s se intersectan
bool IntersecRectaSegmen(const Linea& r, const Linea& s) {
    int t1 = ManoDerecha(r.p, r.q, s.p);
    int t2 = ManoDerecha(r.p, r.q, s.q);
    return (t1 != t2)? true: !t1? true: false;
}

// Saber si dos segmentos s y t se intersectan
bool InterseccionSegmentos(const Linea& s, const Linea& t) {
    int t1 = ManoDerecha(s.p, s.q, t.p);
    int t2 = ManoDerecha(s.p, s.q, t.q);
    if (t1 == t2) {
        if (t1) return false;
        return PuntoEnSegmento(s.p, t) ||
               PuntoEnSegmento(s.q, t) ||
               PuntoEnSegmento(t.p, s) ||
               PuntoEnSegmento(t.q, s);
    }
    return ManoDerecha(t.p, t.q, s.p) !=
           ManoDerecha(t.p, t.q, s.q);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int xli, yli, xlj, ylj, xt, yt, xd, yd;
		cin >> xli >> yli >> xlj >> ylj >> xt >> yt >> xd >> yd;
		bool inter = false;
		
		Linea l = Linea(Punto(xli, yli), Punto(xlj, ylj));
		Linea a = Linea(Punto(xt, yt), Punto(xd, yt));
		Linea b = Linea(Punto(xd, yt), Punto(xd, yd));
		Linea c = Linea(Punto(xt, yd), Punto(xd, yd));
		Linea d = Linea(Punto(xt, yd), Punto(xt, yt));
        
        inter |= InterseccionSegmentos(l, a);
        inter |= InterseccionSegmentos(l, b);
        inter |= InterseccionSegmentos(l, c);
        inter |= InterseccionSegmentos(l, d);        
        
		cout << ((inter)?"T\n":"F\n");
	}		
    return 0;
}
