#include <stdio.h>

int main() {
    int num_empleados, i;
    float horas_trabajadas, valor_hora, ventas, salario_bruto, bonificaciones, salario_neto, aporte_iess, total_salario = 0;
    
    printf("Ingrese el número de empleados: ");
    scanf("%d", &num_empleados);
    
    for(i=1; i<=num_empleados; i++) {
        printf("\nEmpleado %d:\n", i);
        
        printf("Ingrese las horas trabajadas: ");
        scanf("%f", &horas_trabajadas);
        
        printf("Ingrese el valor por hora: ");
        scanf("%f", &valor_hora);
        
        printf("Ingrese el valor de ventas: ");
        scanf("%f", &ventas);
        
        if(horas_trabajadas <= 40) {
            salario_bruto = horas_trabajadas * valor_hora;
        } else if(horas_trabajadas <= 50) {
            salario_bruto = (40 * valor_hora) + ((horas_trabajadas - 40) * (valor_hora * 1.1));
        } else if(horas_trabajadas <= 55) {
            salario_bruto = (40 * valor_hora) + (10 * (valor_hora * 1.1)) + ((horas_trabajadas - 50) * (valor_hora * 1.15));
        } else {
            salario_bruto = (40 * valor_hora) + (10 * (valor_hora * 1.1)) + (5 * (valor_hora * 1.15)) + ((horas_trabajadas - 55) * (valor_hora * 1.2));
        }
        
        if(ventas <= 800) {
            bonificaciones = ventas * 0.02;
        } else if(ventas <= 1500) {
            bonificaciones = 800 * 0.02 + (ventas - 800) * 0.04;
        } else if(ventas <= 3000) {
            bonificaciones = 800 * 0.02 + 700 * 0.04 + (ventas - 1500) * 0.06;
        } else {
            bonificaciones = 800 * 0.02 + 700 * 0.04 + 1500 * 0.06 + (ventas - 3000) * 0.08;
        }
        
        aporte_iess = salario_bruto * 0.0945;
        salario_neto = salario_bruto - aporte_iess + bonificaciones;
        
        printf("Salario: $%.2f\n", salario_neto);
        
        total_salario += salario_neto;
    }
    
    printf("\nTotal de salarios (gasto total de la empresa) de los %d empleados: $%.2f", num_empleados, total_salario);
    
    return 0;
}
