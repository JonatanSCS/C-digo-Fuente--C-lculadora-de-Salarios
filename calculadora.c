#include<stdio.h>
#include<math.h>

float validar_vsm(){
	char vsm_valor[20];
	float vsm; 
	do{
		do{ 
		printf("Ingrese vsm valido:");
		scanf("%s",vsm_valor);
		vsm=atof(vsm_valor); 
		}while(vsm == 0); 
	}while(.9 >= vsm);

	return vsm;
}



int validar_region(char region[100]){

	int i,j;
	char regiones[100] = {65,66,67, 97, 98, 99};
	
	for (i = 0;regiones[i]; ++i){
		if(region[0]==regiones[i])
			return 1;
	}
	
	return 0;
}




int convertir_a_numero(char hrs_semanales_char[100], int multi){
	int i;
	int hrs_semanales=0;
	
	for ( i= 0; hrs_semanales_char[i]; ++i){
		hrs_semanales = hrs_semanales+((hrs_semanales_char[i]-48)*multi);
		multi = multi/10;
	}

	return hrs_semanales;
}



int validar_numero(char hrs_semanales_char[100]){

	int i,j;
	char s[100] ={48,49,50,51,52,53,54,55,56,57};
	int contador = 0;

	for(i = 0; hrs_semanales_char[i]; ++i){
		for(j = 0; s[j]; ++j){
			if (hrs_semanales_char[i]== s[j])
				contador = contador+1;
		}
	}

	if(i == contador)
		return i;
	else
		puts("Horas invalidas, intenta otra vez: ");
	
	return 0;
}

int calculo_salario_normal(int hrs_semanales, int vsm){
	int salario_normal;
	if(hrs_semanales>40)
		salario_normal = 40*vsm;
	else
		salario_normal = hrs_semanales*vsm;
	
	return salario_normal;
}

int calculo_horas_dobles(int hrs_semanales, int vsm){
	int hrs_dobles;
	

	if(hrs_semanales>40)
		hrs_dobles = ((hrs_semanales-40)*vsm)*2;
	else
		return 0;
	

	return hrs_dobles;

}

int calculo_horas_triples(int hrs_domingos, int vsm){
	int hrs_triples;
	hrs_triples = hrs_domingos*3*vsm;

	return hrs_triples;
}


int main(){
	char hrs_semanales_char[100], region[100], hrs_dominos_char[100];
	double vsm;
	int hrs_semanales, hrs_domingos;
	double  salario_normal, hrs_dobles, hrs_triples, total;
	double *j, *k, *l;
	char regiones[] = {'A', 'B', 'C', 'a', 'b', 'c'};
	double region_horas;

	puts("Region\t \tEstados principales\n A\t \t-BAJA CALIFORNIA-DISTRITO FEDERAL-ESTADO DE MEXICO\n B\t \t-JALISCO-NUEVO LEON-SONORA\n C\t \t-CHIAPAS-OAXACA-PUEBLA\n Region\t \tSalario por hora:\n A\t \t$48.6\n B\t \t$47.16\n C\t \t$45.81\n");
	// ASCII del 0 al 9 es del 48 a 57



	puts("Escriba una region donde labora el trabajador(A,B,C): ");
	do{
		int i;
		do{
			scanf("%s",region);
			
			for(i = 0; region[i]; ++i){}
			if(i!=1)
				puts("Region invalida, intente otra vez: ");

		}while(i != 1);
		if(validar_region(region) != 1)
			puts("Region invalida, intente otra vez: ");
		
	} while (validar_region(region) != 1);

	printf("Seleccionada la region '%s'  \n\n\n", region);


	switch(region[0]){
		case 65:
			region_horas = 48.6;
			break;
		case 66:
			region_horas = 47.16;
			break;
		case 57:
			region_horas = 45.81;
			break;
		case 97:
			region_horas = 48.6;
			break;
		case 98:
			region_horas = 47.16;
			break;
		case 99:
			region_horas = 45.81;
			break;
		default:
			region_horas = 45.81;
			break;
	}



	printf("Escriba la cantidad de horas entre semana trabajadas: \n");
	puts("Si se escribe un numero mayor a 144, se tomara este numero como maximo");
	do{

	    	scanf("%s",hrs_semanales_char);

			
		} while (validar_numero(hrs_semanales_char) == 0);
	int cuenta_semana = validar_numero(hrs_semanales_char);
	//Variable multi usada para convertir 
	int multi = pow(10, cuenta_semana-1);
	hrs_semanales = convertir_a_numero(hrs_semanales_char, multi);

	if(hrs_semanales >= 145){
		hrs_semanales= 144;
		printf("'%d' Es una hora valida (máxima)\n", hrs_semanales);

	}
	else{
		printf("'%d' Es una hora valida\n\n", hrs_semanales);

	}




	printf("Escriba la cantidad de horas en Domingo trabajadas: \n");
	puts("Si se escribe un numero mayor a 24, se tomara este nomero como maximo");
	do{

	    	scanf("%s",hrs_dominos_char);

			
		} while (validar_numero(hrs_dominos_char) == 0);
	cuenta_semana = validar_numero(hrs_dominos_char);
	//Variable multi usada para convertir 
	multi = pow(10, cuenta_semana-1);
	hrs_domingos = convertir_a_numero(hrs_dominos_char, multi);

	if(hrs_domingos >= 25){
		hrs_domingos= 24;
		printf("'%d' Es una hora valida (máxima)\n", hrs_domingos);

	}
	else{
		printf("'%d' Es una hora valida\n\n", hrs_domingos);

	}







	puts("Indique cual es el factor VSM del trabajador");
	vsm = validar_vsm();
	printf("El vsm es:%f\n",vsm);
	

	puts("El trabajador percibira esta semana:");
	
	salario_normal = calculo_salario_normal(hrs_semanales, vsm);
	hrs_dobles = calculo_horas_dobles(hrs_semanales, vsm);
	hrs_triples = calculo_horas_triples(hrs_domingos, vsm);

	j = &salario_normal;

	k = &hrs_dobles;

	l = &hrs_triples;
	
	
	salario_normal = salario_normal* region_horas;
	hrs_dobles = hrs_dobles * region_horas;
	hrs_triples = hrs_triples * region_horas;

	printf("Salario normal:\t \t $%f\n", salario_normal);
	printf("Horas dobles: \t \t $%f\n", hrs_dobles);
	printf("Horas triples: \t \t $%f\n", hrs_triples);
	
	
	total = *j+*k+*l;
	printf("Salario total: \t \t $%f\n", total);

	return 0;
}





