#include <stdio.h>
#include <stdlib.h>
// Прототипи
void fill_int_array( unsigned int * uiptr, unsigned int size_of_array );
void fill_float_array( float * fptr, unsigned int size_of_array );
void print_int_array( const unsigned int * uiptr, unsigned int size_of_array );
void print_float_array( const float * fptr, unsigned int size_of_array );
double mean_value( const unsigned int * A, unsigned int Size, unsigned int amount ); //(2)
unsigned int find_min( const unsigned int * A, unsigned int Size ); //(3)
float find_max( const float * B, unsigned int Size ); //(4)

unsigned int sum ( const unsigned int * uiptr, unsigned int size_of_array );
double product( const float * fptr, unsigned int size_of_array );
// Опис функції main()
int main()
{
 unsigned int * A;
 float * B;
 unsigned int Size; // Змінна для збережння розміру динамічного масиву
 unsigned int amount; // змінна для збереження суми елементів масиву А
 double mult; // змінна для збереження добутку елементів масиву В
 double average_value; //(2)
 unsigned int min_value; //(3)
 float max_value; //(4)
 printf("Enter size of array: ");
 scanf("%u", &Size);
 A = (unsigned int *) calloc (Size, sizeof(unsigned int) );
 B = (float *) malloc (Size * sizeof(float) );
 if( A == NULL || B == NULL ){
 printf("Memory has not been allocated");
 exit(0);
 }
 fill_int_array( A, Size );
 fill_float_array( B, Size );
 print_int_array( A, Size );
 print_float_array( B, Size );
 amount = sum( A, Size );
 mult = product( B, Size );
 printf( "\n\nSum = %u", amount );
 printf( "\nProduct = %.3lf", mult );
 mean_value( A, Size, amount );
 find_min( A, Size );
 find_max( B, Size );
 free(A);
 free(B);
 return 0;
}
//----------------- Опис Функцій ------------------------
//--------------------------------------------------------
void fill_int_array( unsigned int * A, unsigned int Size )
{
 unsigned int j;
 unsigned int temp;
 for( j = 0; j <= Size-1; j++ ){
 A[j] = Size - (j + 1);
 }
}
//---------------------------------------------------------
void fill_float_array( float * B, unsigned int Size )
{
 unsigned int j;
 float temp;
 for( j = 0; j <= Size-1; j++ ){
 B[j] = 5.0 * j + 5.0;
 }
}
//-------------------------------------------------------------
void print_int_array( const unsigned int * A, unsigned int Size )
{
 unsigned int j;
 printf("\n\nArray of UNSIGNED INT values:\n");
 for( j = 0; j < Size; j++ )
 printf("%5d", A[j] );
}
//-------------------------------------------------------------
void print_float_array( const float * B, unsigned int Size )
{
 unsigned int j;
 printf("\n\nArray of FLOAT values:\n");
 for( j = 0; j < Size; j++ )
 printf("%7.2f", B[j] );
}
//---------------------------------------------------------------
unsigned int sum (const unsigned int * A, unsigned int Size )
{
 unsigned int j, S;
 S = 0; // змінна, яка використовується для обрахунку значення
// суми елементів масиву
 for( j = 0; j < Size; j++ )
 S += A[j];
 return S;
}
//---------------------------------------------------------------
double product(const float * B, unsigned int Size )
{
 unsigned int j;
 double M;
 M = 1.0; //змінна, яка використовується для обрахунку значення
// добутку елементів масиву
 for( j = 0; j < Size; j++ )
 M *= B[j];
 return M;
}
//---------------------------------------------------------------
double mean_value(const unsigned int * A, unsigned int Size, unsigned int amount )
{
    double average_value;
 average_value = amount/Size;
 printf("\nAverage = %.3lf", average_value);
}
//---------------------------------------------------------------
unsigned int find_min( const unsigned int * A, unsigned int Size )
{
 unsigned int i;
 int min_value = A[1];
    for ( int i = 0; i < Size; i++ ){
        if ( A[i] < min_value )
        {
            min_value = A[i];
        }
    }
 printf( "\nMinimal value of massive A = %d", min_value );
}
//-----------------------------------------------------------------
float find_max( const float * B, unsigned int  Size )
{
 unsigned int i;
 int max_value = B[1];
    for ( int i = 0; i < Size; i++ ){
        if ( B[i] > max_value )
        {
            max_value = B[i];
        }
    }
 printf( "\nMaximal value of massive B = %d\n", max_value );
}
