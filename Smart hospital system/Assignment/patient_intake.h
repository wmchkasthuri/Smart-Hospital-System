#ifndef PATIENT_INTAKE_H_INCLUDED
#define PATIENT_INTAKE_H_INCLUDED

typedef struct {
    int id;
    char name[50];
    int age;
    int emergency_level;
    int specialty_id;
    int is_admitted;
    int ward_id;
    int stay_days;
} Patient;

void register_patient(Patient patients[], int index);
void sort_patients(Patient patients[], int count);
void display_patient(Patient p);
void generate_reports(Patient patients[], int count);
void save_to_file(Patient patients[], int count);

#endif
