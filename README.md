# 🎵 LED Sound Reactive Ring  

## 📌 Description  
Ce projet consiste en une **ring de LEDs** qui change de couleurs et réagit dynamiquement aux sons environnants. Il utilise :  
- Une **carte Arduino** pour traiter les données du capteur.  
- Un **capteur sonore** pour détecter les variations d’intensité sonore.  
- Un **anneau de LEDs** pour afficher des effets lumineux synchronisés avec le son.  
- Une **boîte fabriquée à la main** au FabLab pour intégrer et protéger l’électronique.  

Le programme est entièrement **codé en C++** et tourne sur **Arduino**.  

---

## 🛠 Technologies et Matériel Utilisés  
### 🔹 Matériel  
- **Carte Arduino Uno**  
- **Ring de LEDs NeoPixel**  
- **Capteur de son**  
- **Boîtier fabriqué à la main** (découpe laser)  
- **Alimentation 5V**  

### 🔹 Logiciel  
- **Arduino IDE** (pour programmer la carte)  
- **Bibliothèque Adafruit NeoPixel** (pour contrôler les LEDs)  

---

## 🔧 Installation et Utilisation  
### 1️⃣ Installer l’environnement  
1. **Télécharger et installer** l’[Arduino IDE](https://www.arduino.cc/en/software).  
2. **Ajouter la bibliothèque** Adafruit NeoPixel via le gestionnaire de bibliothèques.  

### 2️⃣ Charger le code sur l’Arduino  
1. **Connecter l’Arduino** au PC via USB.  
2. **Ouvrir le fichier `.ino`** dans l’IDE Arduino.  
3. **Vérifier le bon port et type de carte** dans les paramètres.  
4. **Compiler et téléverser** le programme.  

### 3️⃣ Assemblage  
1. **Connecter le capteur son** à l’Arduino.  
2. **Brancher la ring de LEDs** aux broches correspondantes.  
3. **Placer le tout dans le boîtier**.  

---

## 🚀 Fonctionnement  
Le capteur **mesure le volume sonore** et envoie les données à l’Arduino, qui adapte les couleurs et animations des LEDs en fonction :  
- **Sons faibles** → Effet doux et fluide.  
- **Sons forts** → Changement rapide et éclats lumineux.  
- **Silence** → Mode veille avec une lueur légère.  

---

## ✨ Auteur  
🚀 *Alix Marquer et Jacqueline Rabotchi* - Projet réalisé au **FabLab de Beaulieu à Rennes**  
