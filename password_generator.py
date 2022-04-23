import random

# Pour avoir aléatoirement entre 2 et 4 instances de chaque lettre
lettres_minuscules = 'abcdefghijklmnopqrstuvwxyz' * random.randrange(2, 5)
lettres_majuscules = list(lettres_minuscules.upper())
lettres_minuscules = list(lettres_minuscules)
chiffres = list('0123456789' * random.randrange(2, 5))
caracteres_speciaux = list("&é'(-è_çà)=~#}{[|`^@]+*/ù:!;,<>$£¤µ" + '"')

mdp = lettres_majuscules + lettres_minuscules + caracteres_speciaux + chiffres
random.shuffle(mdp)

taille = random.randrange(8, 15)

password = ''.join(random.sample(mdp, taille))

print("Votre mot de passe est : ", password, len(password))

enregister = input("Enregistrer le mot de passe ? (o/n) : ")
if enregister in ['o', 'O']:
    website = input("Quel est le nom du site ? ")
    with open('mot_de_passe.txt', 'a') as file:
        file.write(website+' : '+password+'\n')
