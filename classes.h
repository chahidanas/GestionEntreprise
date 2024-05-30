#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>
#include <iostream>

class Employe {
public:
    Employe(std::string  nom, double salaire, std::string  departement, int id);

    Employe(const std::string & nom, double salaire, const std::string & string, const std::string & basic_string, double tarif_horaire, const std::string & m_tuteur, int id);

    int getId() const;
    void afficher() const;
    void modifier();

private:
    std::string m_nom;
    double m_salaire{};
    std::string m_departement;
    int m_id{};
};

class Manager : public Employe {
public:
    Manager(const std::string &nom, double salaire, const std::string &departement,
            std::string domaineResponsabilite);

    void afficher() const;
    void modifier();

private:
    std::string m_domaineResponsabilite;
    double m_tarifHoraire{};
};

class Technicien : public Employe {
public:
    Technicien(const std::string &nom, double salaire, const std::string &departement, std::string specialite);

    void afficher() const;
    void modifier();

private:
    std::string m_specialite;
    double m_tarifHoraire{};
};

class Ingenieur : public Employe {
public:
    Ingenieur(const std::string& nom, double salaire, const std::string& departement,
              std::string  domaineExpertise);
    void afficher() const;
    void modifier();

private:
    std::string m_domaineExpertise;
};

class Consultant : public Employe {
public:
    Consultant(const std::string& nom, double salaire, const std::string& departement,
               std::string  domaineConseil, double tarifHoraire);
    void afficher() const;
    void modifier();

private:
    std::string m_domaineConseil;
    double m_tarifHoraire;
};

class Stagiaire : public Employe {
public:
    Stagiaire(const std::string &nom, double salaire, const std::string &departement, std::string domaineConseil,
              double tarifHoraire, std::string &m_tuteur);

    Stagiaire(const std::string &nom, double salaire, const std::string &departement, const std::string &domaineConseil,
              double tarifHoraire, const std::string &m_tuteur, const int &id);

    Stagiaire(const std::string &nom, double salaire, const std::string &departement, std::string domaineConseil,
              const std::string &m_tuteur);

    static void afficher();

    static void modifier();

private:
    std::string m_dureeStage{};
    std::string m_tuteurAssigne;
    std::string m_tuteur;
};

class Entreprise {
public:
    static void afficherDetailsEmployes();
    void ajouterEmploye();
    void modifierEmploye();
    void supprimerEmploye();

private:
    std::vector<Employe> m_employes;
};

#endif //CLASSES_H
