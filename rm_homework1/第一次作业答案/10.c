int decimal,binary=0,i = 1;

int main(){

	scanf("%d",&decimal); 
    while(decimal != 0){
        if(decimal % 2 != 0)
        {
            binary = binary + 1 * i;
        }
        decimal = decimal / 2,i = 10 * i;
    }
    printf("%d\n",binary);
    return 0;
}
