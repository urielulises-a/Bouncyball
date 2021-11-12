#include "miniwin.h"
using namespace miniwin;

void pintaC (int x, int y);
void flechaI (bool &si_izq, bool &si_der);
void flechaD (bool &si_der, bool &si_izq);
void teclas (bool &en_espacio, bool &en_izq, bool &en_der, int lugar_y);
void si_fsalto (int y, bool &espacio);
void mov_yarr (int &altura, bool espacio);
void mov_yaba (int &altura, bool espacio);
void mov_x_izq (int &lado, bool si_izq);
void mov_x_der (int &lado, bool si_der);
void cancela (bool &en_izq, bool &en_der, bool &en_espacio, int lugar_y);

int main(){
	
	vredimensiona(1000,700);
	
//	El -75 es el radio del circulo, para que quede en margen con la pantalla
	bool en_salto;
	bool en_izq;
	bool en_der;
	int eje_x = vancho()/2;
	int eje_y = valto()-75;
	
//	en_salto;
	while (true){
		
		pintaC(eje_x, eje_y);
		
		teclas(en_salto, en_izq, en_der, eje_y);
		
		mov_yarr(eje_y, en_salto);
		mov_yaba(eje_y, en_salto);
		si_fsalto(eje_y, en_salto);
		
		mov_x_izq(eje_x, en_izq);	
		mov_x_der(eje_x, en_der);	
		
		espera(1);
		borra();
		refresca();
	}
}
void pintaC(int x, int y){
	
	circulo(x, y, 75);
}
void flechaI(bool &si_izq, bool &si_der){
	
	if (si_der == true){
		
		si_der = false; 
	}
		
	si_izq = true;
}
void flechaD(bool &si_der, bool &si_izq){
		
	if (si_izq == true){
		
		si_izq = false;
	}
	si_der = true;
}
void teclas(bool &en_espacio, bool &en_izq, bool &en_der, int lugar_y){
	
	int t = tecla();
	
	switch (t){
		
		case 65: flechaI(en_izq, en_der);
		break;
		case 68: flechaD(en_der, en_izq);
		break;
		case 83: cancela(en_izq, en_der, en_espacio, lugar_y);
		break;
		case ESPACIO: en_espacio = true;
		break;
		case ARRIBA: en_espacio = true; 
		break;
		case IZQUIERDA: flechaI(en_izq, en_der);
		break;
		case DERECHA: flechaD(en_der, en_izq);
		break;
		case ABAJO: cancela(en_izq, en_der, en_espacio, lugar_y);
	}
}
void si_fsalto(int y, bool &espacio){ //Determina si el salto ya llego a su fin para cambiar el valor del bool
	
	if (y == valto()/3){
		
		espacio = false;
	}
}
void mov_yarr(int &altura, bool espacio){ //Si se aprietata el espacio se va a desplazar en y
	
	if (espacio == true && altura > valto()/3){
		
		 //valto()/3 define la altura del salto
		altura-= 4;
	}
}
void mov_yaba(int &altura,  bool espacio){
	
	if (espacio == false && altura < valto()-75){ 
			
		altura+= 4;
	}
}
void mov_x_izq(int &lado, bool si_izq){
	
	if (si_izq == true && lado > 75){
		
		lado-= 5;
	}
}
void mov_x_der(int &lado, bool si_der){
	
	if (si_der == true && lado < vancho()-75){
		
		lado+= 5;
	}
}
void cancela(bool &en_izq, bool &en_der, bool &en_espacio, int lugar_y){
	
	if (lugar_y!= valto()-75){
		
		en_espacio = false;
	}
	else{
		
		en_izq = false;
		en_der = false; 
	}
}
