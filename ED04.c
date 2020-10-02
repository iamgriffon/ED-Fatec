#include <stdio.h>
#include <stdlib.h>

//1- escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y.

float express(int x, int y){
	
	if (y<0) {
		int i = -y;
		return (1/(express(x,i)));	
	}
	else if(y==0) return 1;
	else if(y==1) return x;
	else return (x*express(x, y-1));
}

//2. Escrever uma função recursiva que retorna o tamanho de um string, tamstring(char s[])

int tamstring(char s[]){
	if (s[0] == '\0') return 0;
 	return 1+tamstring(&s[1]);
}

//3. Fazer uma função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[])

int carac(char c,char s[]){
	if (s[0] == '\0') return 0;
 	if (s[0] == c) return (1+carac(c,++s));
 	return carac(c,++s);
}

//4. Escreva uma função recursiva que produza o reverso de um string, reverse(char s[])

void ifNot(char s[]) {
	if (s[0] != '\0'){
 		ifNot(&s[1]);
 		printf("%c",s[0]);
	}	
}

