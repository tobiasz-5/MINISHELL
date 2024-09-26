# Our Awesome Shell Project

![Shell Parsing Overview](https://i.ibb.co/DzCHpdY/tekkens.png)

main.c        
Il cuore della shell che contiene:

    shell_loop():         La funzione principale che implementa il ciclo di esecuzione della shell. Chiede l'input all'utente, lo processa e lo esegue.
    process_input():      Funzione che si occupa di processare l'intero input dell'utente, passandolo al lexer per creare i token. Questi token vengono poi visualizzati e utilizzati per l'esecuzione dei comandi.
    Gestione dei segnali: Le funzioni handle_sigint() e handle_sigquit() vengono utilizzate per gestire i segnali come Ctrl+C e Ctrl+\.

    
lexer_utils.c        
Contiene funzioni di utilità per il lexer:

    add_token_to_list():         Aggiunge un nuovo token alla lista collegata di token.
    append_to_temp_token_str():  Funzione che concatena una stringa temporanea al token corrente durante il processo di lexing.
    add_token_node():            Gestisce l'inserimento dei nuovi nodi token nella lista collegata.

    
lexer_token.c        
Il modulo principale del lexer:

    lexer():             La funzione principale del lexer che prende in input una stringa e restituisce una lista di token. Si occupa di analizzare il testo in base ai caratteri speciali come pipe, redirezioni, e quote.
    create_token_node(): Crea un nodo token, copiando la stringa del token e determinando il suo tipo (es. pipe, redirezione, parola, ecc.).

    
process_token.c        
Contiene le funzioni per processare singoli token:

    process_quoted_token(): Gestisce i token racchiusi tra virgolette singole o doppie, trattando il contenuto come un token unico.
    process_normal_token(): Processa un token normale (senza virgolette).
    process_token():        Funzione che decide quale tipo di token processare (normale o con virgolette).
    process_next_token():   Avanza nell'input e crea il token successivo, gestendo correttamente la creazione dei nodi per i token.

    
token_analize_utils.c        
Utilità per l'analisi dei token:

    find_closing_quote():          Trova la posizione della chiusura di una quote.
    handle_unclosed_quote_error(): Gestisce errori nel caso di quote non chiuse, liberando le risorse allocate.
    set_quote_flag():              Imposta i flag per il tipo di quote (single_quote, double_quote).
    handle_token_error():          Gestisce gli errori relativi ai token e libera la memoria.
    init_lexer_vars():             Inizializza le variabili necessarie per il lexer, come head, tail e lo stato del lexer.

    
token_type.c        
Contiene funzioni per determinare e descrivere il tipo di token:

    token_type_to_string(): Converte il tipo di token in una stringa leggibile per la stampa.
    determine_token_type(): Determina il tipo di un token in base alla stringa (es. pipe, redirezione, parola, ecc.).

    
token_utils.c        
Funzioni di utilità generiche:

    ft_memcpy():   Implementazione personalizzata della funzione memcpy per copiare blocchi di memoria.
    ft_strjoin():  Concatena due stringhe in una nuova area di memoria.
    skip_spaces(): Salta gli spazi nell'input durante il parsing.
