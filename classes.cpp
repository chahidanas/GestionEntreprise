#include "classes.h"

#include <utility>

Employe::Employe(std::string  nom, double salaire, std::string  departement, int id)
    : m_nom(std::move(nom)), m_salaire(salaire), m_departement(std::move(departement)), m_id(id) {
}

Employe::Employe(const std::string &nom, double salaire, const std::string &string, const std::string &basic_string,
    double tarif_horaire, const std::string &m_tuteur, int id) {
}

int Employe::getId() const {
    return m_id;
}

void Employe::afficher() const {
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "Nom: " << m_nom << std::endl;
    std::cout << "Salaire: " << m_salaire << std::endl;
    std::cout << "Département: " << m_departement << std::endl;
}

void Employe::modifier() {
    std::cout << "Nouveau nom : ";
    std::cin >> m_nom;
    std::cout << "Nouveau salaire : ";
    std::cin >> m_salaire;
    std::cout << "Nouveau département : ";
    std::cin >> m_departement;
}

Manager::Manager(const std::string& nom, double salaire, const std::string& departement,
                 std::string  domaineResponsabilite)
    : Employe(nom, salaire, departement, 0), m_domaineResponsabilite(std::move(domaineResponsabilite)) {
}

void Manager::afficher() const {
    Employe::afficher();
    std::cout << "Domaine de responsabilité: " << m_domaineResponsabilite << std::endl;
}

void Manager::modifier() {
    Employe::modifier();
    std::cout << "Nouveau domaine de responsabilité : ";
    std::cin >> m_domaineResponsabilite;
}

Technicien::Technicien(const std::string& nom, double salaire, const std::string& departement,
                       std::string  specialite)
    : Employe(nom, salaire, departement, -1), m_specialite(std::move(specialite)) {
}

void Technicien::afficher() const {
    Employe::afficher();
    std::cout << "Spécialité: " << m_specialite << std::endl;
}

void Technicien::modifier() {
    Employe::modifier();
    std::cout << "Nouvelle spécialité : ";
    std::cin >> m_specialite;
}

Ingenieur::Ingenieur(const std::string& nom, double salaire, const std::string& departement,
                     std::string  domaineExpertise)
    : Employe(nom, salaire, departement, -1), m_domaineExpertise(std::move(domaineExpertise)) {
}

void Ingenieur::afficher() const {
    Employe::afficher();
    std::cout << "Domaine d'expertise: " << m_domaineExpertise << std::endl;
}

void Ingenieur::modifier() {
    Employe::modifier();
    std::cout << "Nouveau domaine d'expertise : ";
    std::cin >> m_domaineExpertise;
}

Consultant::Consultant(const std::string& nom, double salaire, const std::string& departement,
                       std::string  domaineConseil, double tarifHoraire)
    : Employe(nom, salaire, departement, -1),
      m_domaineConseil(std::move(domaineConseil)),
      m_tarifHoraire(tarifHoraire) {
}

void Consultant::afficher() const {
    Employe::afficher();
    std::cout << "Domaine de conseil: " << m_domaineConseil << std::endl;
    std::cout << "Tarif horaire: " << m_tarifHoraire << std::endl;
}

void Consultant::modifier() {
    Employe::modifier();
    std::cout << "Nouveau domaine de conseil : ";
    std::cin >> m_domaineConseil;
}

Stagiaire::Stagiaire(const std::string &nom, double salaire, const std::string &departement,
std::string domaineConseil, const std::string& tuteur) : Employe(nom, salaire, departement, 0),
                                                         m_dureeStage(std::move(domaineConseil)),
                                                         m_tuteur(tuteur) {
}

Stagiaire::Stagiaire(const std::string &nom, double salaire, const std::string &departement,
                     const std::string &domaineConseil, double tarifHoraire,
                     const std::string &m_tuteur, const int &id): Employe(nom, salaire, departement, domaineConseil, tarifHoraire, m_tuteur,id) {
}

void Stagiaire::afficher() {
}

void Stagiaire::modifier() {
}

void Entreprise::afficherDetailsEmployes() {

}

void Entreprise::ajouterEmploye() {
    std::string nom;
    double salaire;
    std::string departement;

    // Demande à l'utilisateur de saisir les détails de l'employé
    std::cout << "Saisissez le nom de l'employe : ";
    std::cin >> nom;
    std::cout << "Saisissez le salaire de l'employe : ";
    std::cin >> salaire;
    std::cout << "Saisissez le département de l'employe : ";
    std::cin >> departement;

    std::vector<Employe>::size_type nouvelId;
    nouvelId = m_employes.size() + 1;
    Employe nouvelEmploye(nom, salaire, departement, nouvelId);
    std::cout << "ID de l'employe : " << nouvelId;
    nouvelId = 1;

    // Ajoute cet employé à la liste m_employes
    m_employes.push_back(nouvelEmploye);
}

void Entreprise::modifierEmploye() {
    int id;
    std::cout << "Saisissez l'ID de l'employé à modifier : ";
    std::cin >> id;

    // Recherchez l'employé avec l'ID donné dans la liste m_employes
    for (Employe& employe : m_employes) {
        if (employe.getId() == id) {
            // Appelez la méthode modifier() de cet employé pour mettre à jour ses détails
            employe.modifier();
            return; // Sortez de la boucle dès que l'employé est trouvé
        }
    }

    std::cout << "Aucun employé trouvé avec l'ID " << id << ". Veuillez réessayer.\n";
}

void Entreprise::supprimerEmploye() {
    int id;
    std::cout << "Saisissez l'ID de l'employé à supprimer : ";
    std::cin >> id;

    // Recherchez l'employé avec l'ID donné dans la liste m_employes
    for (auto it = m_employes.begin(); it != m_employes.end(); ++it) {
        if (it->getId() == id) {
            // Supprimez cet employé de la liste
            m_employes.erase(it);
            std::cout << "Employé avec l'ID " << id << " supprimé.\n";
            return; // Sortez de la boucle dès que l'employé est trouvé
        }
    }

    std::cout << "Aucun employé trouvé avec l'ID " << id << ". Veuillez réessayer.\n";
}