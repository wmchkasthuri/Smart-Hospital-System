#include <stdio.h>
#include <string.h>
#include "patient_intake.h"
#include "hospital_data.h"

int specialty_queue_count[5] = {0};

void register_patient(Patient patients[], int index) {
    patients[index].id = 1001 + index;

    printf("\n--- Registering Patient #%d ---\n", index + 1);
    printf("Enter Patient Name: ");
    fgets(patientss[index].name, sizeof(patients[index].name), stdin);
    patients[index].name[strcspn(patients[index].name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &patients[index].age);

    printf("Enter Emergency Status (1: Normal, 2: Urgent, 3: Critical): ");
    scanf("%d", &patients[index].emergency_level);

    int valid_selection = 0;
    while (!valid_selection) {
        display_specialties();
        printf("Select Specialty ID (1-4): ");
        scanf("%d", patients[index].specialty_id);

        int spec_id = patients[index].specialty_id;
        int max_cap = get_specialty_cap(spec_id);

        if (spec_id >= 1 && spec_id <=4) {
            if (specialty_queue_count[spec_id] >= max_cap) {
                printf("\n[!] Sorry! Daily Patient Cap (%d) reached for this Specialty. Please select another specialty.\n", max_cap);
            }
            else {
                    printf("\n[!] Invalid Specialty ID! Please select between 1 and 4.\n");
            }
        }
    }

    printf("Is Addmitted to Ward? (1: Yes, 0: No): ");
    scanf("%d", &patients[index].is_addmitted);

    if (patients[index].is_addmitted == 1) {
        display_wards();
        printf("Select Ward ID (1-4): ");
        scanf("%d", &patients[index].ward_id);

        printf("Enter Expected Days of Stay: ");
        scanf("%d", &patients[index].stay_days);
    }
    else {
        patients[index].ward_id = 0;
        patients[index].stay_days = 0;
    }
    getchar();
}

void sort_patients(Patient patients[], int count) {
    for (int i=0 ; i<count-1 ; i++) {
        for (int j =0 ; j<count-i-1 ; j++) {
            if (patients[j].emergency_level < patients[j+1].emergency_level) {
                Patient temp = patients[j];
                patients[j] = patients[j+1];
                patients[j+1] = temp;
            }
        }
    }
}



























