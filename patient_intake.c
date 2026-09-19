#include <stdio.h>
#include <string.h>
#include "patient_intake.h"
#include "hospital_data.h"

int specialty_queue_count[5] = {0};

void register_patiene(Patient patients[], int index) {
    patients[index].id = 1001 + index;

    printf("\n--- Registering Patient #%d ---\n", index + 1);
    printf("Enter Patient Name: ");
    fgets(patientss[index].name, sizeof(patients[index].name), stdin);
    patients[index].name[strcspn(patients[index].name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &patients[index].emergency_level);


}
