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

void display_patient(Patient p) {
    float doc_fee = get_specialty_fee(p.specialty_id);
    int avg_time = get_specialty_time(p.specialty_id);

    float surge_rate = 0.0;
    if (p.emergency_level == 2) surge_rate = 0.20;
    else if (p.emergency_level == 3) surge_rate = 0.05;

    float surge_charge = doc_fee * surge_rate;
    float ward_cost = (p.is_addmitted == 1) ? get_ward_rate(p.ward_id) * p.stay_days : 0.0;
    float gross_total = doc_fee + surge_charge + ward_cost;

    float discount = 0.0;
    if (p.age < 5 || p.age > 65) {
        discount=gross_total*0.15;
    }

    float final_amount = gross_total-discount;
    float wait_time = (p.emergency_level == 3) ? 0.0 : (specialty_queue_count[p.specialty_id]-1)*avg_time;

    printf("\n====================================================\n");
    printf("         SMART HOSPITAL ADMISSION & BILL              \n");
    printf("------------------------------------------------------\n");
    printf("Patient Id     : PAT-%d\n", p.id);
    printf("Patient Name   : %s\n", p.name);
    printf("Age            : %d Years %s\n", p.age, (discount > 0) ? "(15% Subsidy Eligible" : "");
    printf("Specialty ID   : %d\n", p.specialty_id);
    printf("Assigned Ward  : %s\n", (p.is_addmitted == 1) ? "Ward Addmitted" : "OPD / Outpatient");
    printf("Urgency Level  : Level %d (%s)\n", p.emergency_level, (p.emergency_level == 3) ? "Critical" : (p.emergency_level == 2) ? "Urgent" : "Normal");
    printf("------------------------------------------------------\n");
    printf("Base Consultation Fee : LKR %.2f\n", doc_fee);
    printf("Emergency Surcharge   : LKR %.2f (%.0f%%)\n", surge_charge, surge_rate * 100);
    printf("Ward Stay Cost (%d Days) : LKR %.2f\n", p.stay_days, ward_cost);
    printf("------------------------------------------------------\n");
    printf("Gross Total Bill      : LKR %.2f\n", gross_total);
    printf("Age Subsidy Discount  : -LKR %.2f (15%%)\n", discount);
    printf("------------------------------------------------------\n");
    printf("Final Payable Amount  : LKR %.2f\n", final_amount);
    printf("Estimated Waiting Time: %.2f mins %s\n", wait_time, (p.emergency_level == 3) ? "(Immediate Attention)" : "");
    printf("======================================================\n");
}

























