# PIPEX

### Apprendre les fonctions : 

- access ✅
- dup2 ✅
- execve ✅ 
- fork ✅
- unlink ✅
- pipe ✅
- wait ✅


### PARSING

- Verifier si il y a le bon nombres d'arguments   ✅
- Verifier si j'ai le droit d'ouvrir le premier fichier   ✅
- Verifier si j'ai le droit d'ouvrir le deuxieme fichier ✅
- Verifier si la commande est valid :
	. trouver si le chemin existe (path envp)  ✅
	. separer le path (ils sont separer par : donc use split) ✅
	. isoler la parti de la commande qu'il me faut ✅
	. verifier avec quel parti du path la commande est executable (X_OK) ❌ 
		. rassemble la commande **arg_cmd1 avec le lien corespondant. ✅
		. trouver le chemin executable ❌
		. l'envoyer a path_cmd1 ❌
	
### Processus enfant 

- Capture la sortie standard et le mettre dans un tube ❌
- Fermer l'autre bout du tube. ❌
- Le rediriger vers un fichier d'entrée ❌
- La commande argv[2] la decouper en deux et la stock dans un tab ❌
- Verifier si on trouve le bon chemin pour la commande ❌
- Gestion des cas d'erreur ❌
- free + message d'erreur + exit ❌
- Exerve (remplace le processus actuel par le nouveau executable, le chemin complet) ❌



### Creation de la struct 

- Creer la struct  ✅


### Faire un Makefile 
- Makefile ✅

### Comprendre l'importance de fork dans ce projet 
- comprendre pourquoi utiliser fork ✅ 
   
   ✅ ❌

 

> [!IMPORTANT]
> Source : https://reactive.so/post/42-a-comprehensive-guide-to-pipex

