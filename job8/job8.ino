#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialisation de l'afficheur LCD

int progress = 0; // Initialisation de la barre de progression
int progressMax = 16; // Longueur de la barre de progression

void setup() {
  lcd.begin(16, 2); // Initialisation de la taille de l'afficheur LCD
}

void loop() {
  lcd.setCursor(0, 0); // Positionnement du curseur en haut à gauche de l'afficheur LCD
  
  // Affichage du pourcentage de chargement
  int percentage = (progress * 100) / progressMax; // Calcul du pourcentage de chargement
  lcd.print("Loading: ");
  lcd.print(percentage);
  lcd.print("%");
  
  lcd.setCursor(0, 1); // Positionnement du curseur en bas à gauche de l'afficheur LCD
  
  // Affichage de la barre de progression
  for (int i = 0; i < progressMax; i++) {
    if (i < progress) {
      lcd.print("#");
    } else {
      lcd.print(" ");
    }
  }
  
  progress++; // Incrémentation de la barre de progression
  
  // Si la barre de progression est remplie, réinitialisation de la progression
  if (progress > progressMax) {
    progress = 0;
  }
  
  delay(3000); // Pause de 3 secondes avant la mise à jour de la barre de progression
}
