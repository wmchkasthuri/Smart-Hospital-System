#include <stdio.h>
#include "hospital_data.h"
#include "patient_intake.h"

int main() {
    initialize_beds();

    int patient_count;
    printf("================ SMART HOSPITAL SYSTEM ================\n");
    printf("Enter number of patients to register: ");
    scanf("%d", &patient_count);
    getchar();

    Patient patients[patient_count];

    for (int i = 0; i < patient_count; i++) {
        register_patient(patients, i);
    }

    sort_patients(patients, patient_count);

    for (int i = 0; i < patient_count; i++) {
        display_patient(patients[i]);
    }

    generate_reports(patients, patient_count);
    save_to_file(patients, patient_count);

    return 0;
}
