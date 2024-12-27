/**
 * DMOJ - Día nublado
 * Temáticas: Sweep Line
 *
 * Idea: Tenemos un grupos de ciudades ubicadas a lo largo de una dimesión donde
 * cada ciudad cuenta con una cantidad de habitantes de igual forma a largo de esa
 * dimesión tenemos nubes las cuales están en una posición y cubren determinado
 * rango. Se quiere calcular la maxima cantidad de habitantes que van a tener
 * un dia soleado se considera que un habitante tiene un dia soleado si su ciudad
 * no esta cubierta por una nube. Ademas se cuenta con la capacidad de remover una
 * nube.
 *
 * Para solucionar el problema vamos a atacarlo con un enfoque de linea de barrido
 * (sweep line) para eso vamos a definir los posibles eventos que vamos a
 * procesar de forma ordena ascedentemente de acuerdo a su posición. Los posibles
 * eventos son:
 *
 * 1. Inicio de la nube cuya posicion es igual a la posicion de la nube menos el
 * rango que ella cubre.
 * 2. Ciudad cuya posicion es la posicion de la ciudad
 * 3. Fin de la nube cuya posicion es igual a la posicion de la nube mas el
 * rango que ella cubre.
 *
 * Una vez definido los eventos los ordenamos de acuerdo a su posicion en caso de
 * eventos en la misma posicion debemos tratar que una ciudad siempre este entre
 * los rangos de inicio o fin de la nube que comparte la misma posicion de igual
 * el fin de una nube debe ir primero que el inicio de una nube cuyo extremos(
 * fin e inicio sean iguales)
 *
 * Pasamos a procesar los eventos en los cuales vamos a llevar el listado de las
 * nubes activas (una nube esta activa si la posicion de barrido donde estoy esta
 * dentro del rango que cubre la nube). El evento que prestaremos especial atencion
 * será ciudad. Si proceso un evento de tipo de ciudad verifico dos situaciones
 *
 * 1. No existe nubes activa esto siginifica que los habitantes de esa ciudad
 * tendrán un dia soleado.
 * 2. Existe una sola nube activa esto implica que si quitaramos esa nube esos habi
 * tantes tendrían un dia soleado. En este caso por cada nube vamos a tener un
 * acumulador que cuando suceda esto ese acumulador de esa unica nube activa se le
 * incrementa en una cantidad igual a los habitantes de la ciudad.
 *
 * Luego como parte de la solución solo debemos buscar aquella nube con mayor
 * acumulado y será la que debemos quitar y su acumulado será tambien parte de la
 * solución.
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1005
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

enum TYPE_EVENT {
	BEGIN_CLOUD, CITY, END_CLOUD, UNDEFINED
};

struct Event {
	ULL pos;
	TYPE_EVENT type;
	int index;

	Event(TYPE_EVENT t = UNDEFINED, ULL p = 0, int idx = 0){
		this->type = t;
		this->pos = p;
		this->index = idx;
	}
};

struct Cloud {
	int index;
	ULL pos;
	ULL radius;
	ULL habitans;

	Cloud(int idx = 0, ULL p = 0, ULL r = 0, ULL h = 0) {
		this->index = idx;
		this->pos = p;
		this->radius = r;
		this->habitans = 0;
	}
};

struct City {
	int index;
	ULL habitans;
	ULL pos;

	City(int idx = 0, ULL p = 0, ULL h = 0) {
		this->index = idx;
		this->habitans = h;
		this->pos = p;
	}
};

bool operator<(const Event &a, const Event &b) {
	if (a.pos < b.pos)
		return true;
	else if (a.pos > b.pos)
		return false;
	else {
		if (a.type == BEGIN_CLOUD && (b.type == BEGIN_CLOUD || b.type == CITY))
			return true;
		if (a.type == CITY && b.type == END_CLOUD)
			return true;
		if (a.type == END_CLOUD && b.type == BEGIN_CLOUD)
			return true;

		return false;
	}
}

ostream & operator<<(ostream & out, Event event){
	out<<"Type:"<<event.type<<" pos:"<<event.pos<<" index:"<<event.index;
	return out;
}

int main() {
	OPTIMIZAR_IO
	//PRESICION(20)
	int ncitys, nclouds;
	ULL nogros = 0,cloudRemove = 0;
	vector<Event> events;

	cin >> ncitys;

	vector<City> citys(ncitys);

	set<int> cloudsActive;

	for (int i = 0; i < ncitys; i++) {
		cin >> citys[i].habitans;
		citys[i].index = i;
	}

	for (int i = 0; i < ncitys; i++) {
		cin >> citys[i].pos;
	}

	cin >> nclouds;

	vector<Cloud> clouds(nclouds);

	for (int i = 0; i < nclouds; i++) {
		cin >> clouds[i].pos;
		clouds[i].index = i;
		clouds[i].habitans = 0;
	}

	for (int i = 0; i < nclouds; i++) {
		cin >> clouds[i].radius;
	}

	for(int i=0;i<ncitys;i++){
		events.push_back(Event(CITY,citys[i].pos,citys[i].index));
	}

	for(int i=0;i<nclouds;i++){
		events.push_back(Event(END_CLOUD,clouds[i].pos+clouds[i].radius,clouds[i].index));
		if(clouds[i].pos < clouds[i].radius)
			events.push_back(Event(BEGIN_CLOUD,0,clouds[i].index));
		else
			events.push_back(Event(BEGIN_CLOUD,clouds[i].pos - clouds[i].radius,clouds[i].index));


	}

	sort(events.begin(),events.end());

	for(Event e : events){
		if(e.type == END_CLOUD){
			cloudsActive.erase(e.index);
		}else if (e.type == BEGIN_CLOUD){
			cloudsActive.insert(e.index);
		}else if (e.type == CITY){
			if(cloudsActive.empty()==true){
				nogros+=citys[e.index].habitans;
			}else if(cloudsActive.size()==1){
				clouds[*cloudsActive.begin()].habitans+=citys[e.index].habitans;
			}
		}
	}

	for (int i = 0; i < nclouds; i++) {
		cloudRemove = max(cloudRemove,clouds[i].habitans);
	}

	cout<<nogros + cloudRemove<<ENDL;

	return 0;
}

