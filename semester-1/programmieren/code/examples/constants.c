#define X 10


int main()
{
    printf("%d\n", X);
    
    #define X 20 
    printf("%d\n", X);
    
    return 0;
}