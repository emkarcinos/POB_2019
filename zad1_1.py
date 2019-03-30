class Przedmiot():
    def __init__(self, subject):
        self.name=subject

    def __str__(self):
        return self.name

subjects=[]
subjects.append(Przedmiot("Maths"))
subjects.append(Przedmiot("Physics"))
subjects.append(Przedmiot("PE"))
subjects.append(Przedmiot("Chemistry"))
subjects.append(Przedmiot("Computer Science"))

for subject in subjects:
    print(subject)