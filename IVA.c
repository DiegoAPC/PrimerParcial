#include <stdio.h>

int main () {
    float iva, precio, total;
    int opcion;
    do {
        FILE *archivo = fopen("salida.txt", "r");

        
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        
        printf("\n------------------\n");
        printf("Menu:\n");
        printf("1. Calcular IVA\n");
        printf("2. Ver historial\n");
        printf("3. Borrar historial\n");
        printf("4. Salida\n");
        printf("Elije una opcion: ");
        scanf("%d", &opcion); 

        switch (opcion) {
            case 1:
                printf("Ingrese el precio total a calcular \n");
                scanf("%f", &precio);

                iva = precio * 0.12;
                total = precio - iva;


                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fprintf(archivo,"La cantidd de IVA que se paso es de %f\n", iva);
                fprintf(archivo,"La cantidd sin IVA que se paso es de %f\n", total);
                fclose(archivo); 

                printf("La cantidd de IVA que se pago es de %f\n", iva);
                printf("La cantidd sin IVA que se pago es de %f\n", total);
                break;

            case 2:
                printf("Historial de IVA:\n");
                char linea[100]; 
                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                    printf("%s", linea); 
                }
                fclose(archivo); 

                break;

            case 3:
                archivo = fopen("salida.txt", "w");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fclose(archivo); 
                printf("Historial borrado.\n");
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Por favor, elija una opcion valida.\n");
                break;
        }
    } while (opcion != 4); 

    return 0;

}