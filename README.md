1)

	ΒΑΣΙΛΕΙΟΣ ΡΟΥΣΣΟΣ 	ΑΜ: 1115200700224
	ΕΥΑΓΓΕΛΟΣ ΜΩΡΑΪΤΗΣ 	ΑΜ: 1115202000149

2)

	g++ -o exec main.cpp highway.cpp collector_toll.cpp digital_toll.cpp entrance.cpp segment.cpp toll.cpp vehicle.cpp
	
3)

	./exec 10 10 10 75

10 15 5 25
5 5 5 75
10 10 10 50

4)
	
	Ανάλυση των κλάσεων της εργασίας και κάποιων σχεδιαστικών επιλογών.
	
	highway:
		Επιλέξαμε ένα vector από δείκτες σε segments για την απεικόνηση των τμημάτων του αυτοκινητοδρόμου. Τα segments δημιουργούνται και έπειτα με μια συναρτηση (connect_segments) ενώνονται για να δημιουργήσουν τον αυτοκινητόδρομο.
		
	segment:
		Επιλέξαμε ένα vector από δείκτες σε οχήματα για την απεικόνηση των οχημάτων που βρίσκονται μέσα στα τμήματα. Ο κάθε vector ξεκινάει με έναν τυχαίο αριθμό οχηματων μετά την δημιουργία του.
		Φτιάξαμε επιπλέον δύο getters-setters για να ενωθούν τα τμήματα από τον αυτοκινητόδρομο, την get_ready_vehicles_num που επιστρέφει πόσα έτοιμα οχήματα υπάρχουν στο τμήμα για να γίνει ο έλεγχος στην εκτύπωση μηνυμάτων, η ready_vehicles_exist
		τελικά δεν χρησιμοποιήθηκε λόγο παραμετροποίησης στον κώδικα, αλλά επιστρέφει αν υπάρχουν έτοιμα οχήματα, και η get_ready_to_exit ετοιμάζει κάποια οχήματα, ανάλογα με το Percent και καλείται μετά στο τέλος του κάθε operate.
		
	entrance:
		Τα διόδια αναπαριστούνται από δύο vectors με δείκτες σε διόδια, έναν για κάθε κατηγορία. Η συναρτήση reinit_all, ξαναγεμίζει με οχήματα τα διόδια, η max_is_reached ελεγχει αν πέρασε ο μέγιστος αριθμός οχημάτων, η get_K επιστρέφει το τρέχον K
		της εισόδου, η increase_limit αυξάνει το Κ, η decrease_limit αντιστοιχα, η is_empty επιστρέφει αν είναι όλα τα διόδια αδεια(δεν χρησιμοποιήθηκε τελικα) και η get_num_of_vehicles επιστρέφει τον συνολικό αριθμό οχημάτων που περιμένουν.
		
	toll:
		Τα διόδια έχουν ένα δείκτη της εισόδου που ανήκουν για να λαμβάνουν το τρέχον Κ όταν χρειάζεται. Επίσης τα οχήματα αναπαριστούνται από ενα deque δεικτών σε οχήματα. Το deque επιλέχτηκε για να υλοποιηθεί με ακρίβεια ο copy constructor(πιο εύκολο deep copy), 
		ο οποίος έγινε καθαρά για εξάσκηση. Φτιάξαμε τις συναρτησεις reinit που επαναφέρει το διόδιο στην αρχική κατάσταση γεμίζοντας το παράλληλα, την recieve_vehicle η οποία επιστρέφει ένα όχημα από το διόδιο, τη limit_is_reached που επιστρέφει αν
		το Κ έχει πιαστεί, και το toll_is_empty που επιστρέφει αν υπάρχουν οχήματα στο διόδιο.
	
	vehicle: 
		Για το οχήματα πέρα από τα ζητούμενα φτιάξαμε συναρτήσεις get_destination που επιστρέφει τον προορισμό, set_possition που βάζει τη θέση του τμήματος που μπαίνει το όχημα και setter - getter για την κατάσταση ετοιμότητας.
	
5)
	Ανάλυση του τρόπου υλοποίησης και της λογικής των συναρτήσεων των κλάσεων(όπου είναι σκόπιμο για την κατανόηση)
	
	highway:
		connect_segments --> Ανάλογα με τη θέση που είναι το κάθε segment γίνεται η αντοίστοιχη ένωση, βάζοντας την κατάλληλη πληροφορία στους δείκτες previousSegment και nextSegment μεσω των setters
		operate --> Λειτουργούν όλα τα segments από το τελευταίο προς το πρώτο, ενημερώνοντας ταυτόχρονα και τον μετρητή των οχημάτων για τη διαφορά που προκύπτει μετά από κάθε operate τμήματος.
		

	segment:
		get_ready_to_exit --> Υπολογίζει έναν αριθμό οχημάτων με βάση το ποσοστό και διασχίζει τον vector των οχημάτων και αν κάποιο όχημα δεν είναι έτοιμο το ετοιμάζει, αλλιώς αυξάνει τον αρχικό αριθμό προκυμένου να μην "μετρηθει" το όχημα και να 
							  γίνει έτοιμο κάποιο επόμενο στη θέση του, αν υπάρχει.	
		segment(constructor) --> Βρίσκει έναν τυχαίο αριθμό αρχικών οχημάτων, και δημιουργεί και τα βάζει στον αντιστοιχο vector, με τυχαία κατάσταση ετοιμότητας.
		enter --> Κανει operate της εισόδου του τμήματος, περνώντας σαν όρισμα τον vector οχημάτων.
		exit --> Διαγράφει τα οχήματα που εχούν προορισμό τον επόμενο κόμβο. Για καταφέρουμε αυτό, χρησιμοποιήθηκε iterator, για να μπορέσουμε να διαγράψουμε οχήματα από μία ενδιάμεση θέση του vector και να μην μείνει κενή, κάνοντας πιο περίπλοκη
				 μετέπειτα λογική.
		pass --> Κάνει τους απαραίτητους ελέγχους και αν πληρούνται οι προϋποθέσεις περνάνε τα οχήματα από το ένα τμήμα στο άλλο. Πάλι χρησιμοποιήθηκε iterator για τη διαγραφή της θέσης στο τμήμα που στέλνει το όχημα στο επόμενο segment.
		operate --> Αρχικά βγαίνουν τα οχήματα που έχουν προορισμό τον επόμενο κόμβο, μετά περνάνε τα οχήματα από το προηγούμενο segment και μετά μπαίνουν τα οχήματα από την είσοδο. Εκτυπώνονται τα κατάλληλα μυνήματα, μετά από τους αντίστοιχους 
					ελέγχους, ετοιμάζονται τα οχήματα για την επόμενη λειτουργεία και επιστρέφεται η διαφορά των οχημάτων που προκύπτει από το operate. Δεν λαμβανονται υπ'οψη τα οχήματα από το προηγούμενο τμημα καθώς ήδη υπάρχουν μέσα στον αυτοκινητόδρομο.
		get_ready_vehicles_num --> Επιστρέφει το πόσα οχήματα είναι έτοιμα στο τμήμα.
		ready_vehicles_exist --> Επιστρέφει αν υπάρχουν έτοιμα οχήματα ή οχι.
		
	entrance:
		reinit_all --> Καλεί την reinit του κάθε διοδίου.
		max_is_reached --> Ελέγχει αν σε όλα τα διόδια μπήκε ο μέγιστος αριθμός οχημάτων Κ.
		operate --> Ελέγχει αν χωράνε οχήματα στον vector που δέχεται σαν όρισμα και αν ναι τοποθετεί στον vector του segment οχήματα από τα δυόδια. Αλλάζει το όριο Κ, ανάλογα με το αν πιαστηκε ο μέγιστος αριθμός και επιστρέφει τον αριθμό οχημάτων 
					που περιμένουν μετά την λειτουργεία.
		is_empty --> Επιστρέφει αν όλα τα δυοδια είναι άδεια ή οχι.
		
	toll:
		recieve_vehicle--> Ελεγχει αν έχει πιαστει το όριο και αν υπάρχουν οχήματα και επιστρέφει ένα όχημα σε αυτή την περίπτωση.
		reinit(overide) --> Θέτει έναν αριθμό οχημάτων που πρέπει να ξεκινάει το διοδιο τυχαία από Κ έως 2Κ και το διπλό για τα digital_tolls και βάζει οχήματα μέχρι να πιαστεί αυτός ο αριθμός.