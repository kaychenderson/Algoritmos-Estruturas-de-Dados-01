int comprimento (char* s){
    int i;
    int n = 0;
    for(i = 0; s[i] != '\0'; i++){
        n++;
    }
    return n;
}

void copia(char* dest, char* orig){
    int i;
    for(i = 0; orig[i] != '\0'; i++){
        dest[i] = orig[i];
    }
    dest[i] = '\0';
}

void concatena(char* dest,char* orig){
    int i = 0; //Indice usado na cadeia destino, inicializado com 0
    int j; //Indice usado na cadeia destino
    //Acha o final da cadeia destino
    while(dest[i] != '\0')
        i++; //Copia os elementos da orgiem para o final do destino
    for( j = 0; orig[j] != '\0'; j++){
        dest[i] = orig[j];
        i++;
    }
    //Fecha cadeia destino
    dest[i] = '\0';
}