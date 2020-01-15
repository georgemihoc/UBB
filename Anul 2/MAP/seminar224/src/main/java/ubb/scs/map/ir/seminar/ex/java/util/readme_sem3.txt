Collections and Generics - sem 3

I.	1) Creaţi o clasǎ Student avand urmatorii membri: nume(String), media(float), un constructor cu parametrii care initializeaza un Student si metoda toString();
Instantiati urmatorii studenti:
Student  s1= new    Student("Dan", 4.5f);
Student  s2= new    Student("Ana", 8.5f);
Student  s3= new    Student("Dan", 4.5f);
2)	Instantiati un obiect de tip HashSet<Student> si adaugati studentii de la punctul I.1. Ce observati?
3)	Respectati Contractul equals - hashcode: dacă obj1.equals(obj2) atunci obj1. hashCode() == obj2.hashCode().
Atunci cand doriti sa salvati obiecte în colecții ce sunt  reprezentare in memorie pe tabele de dispersie (hash table),  dacă implementați equals()trebuie sa implementati și hashcode().
4)	Instantiati un obiect de tipul TreeSet<Student> si adaugati studentii de la punctul I.1). Definiti un comparator care compara doi studenti dupa nume.
5)	Repetati exercitiile 2-4 folosind HashMap si TreeMap

II.	Scrieţi o clasǎ MyMap, ce va reprezenta un Map pentru reţinerea studenţilor dupǎ medie. Caracteristicile clasei definite sunt:
1)	Cheile pot avea valori de la 0 la 10 (corespunzǎtoare mediilor posibile).
2)	Valoarea asociată fiecǎrei chei va fi o listǎ (List) care va reţine toţi studenţii cu media rotunjitǎ egalǎ cu cheia. Considerǎm cǎ un student are media rotunjitǎ 8 dacǎ media sa este în intervalul [7.50, 8.49]. (Math.round)
3)	Map-ul vostru va menţine cheile (mediile) ordonate descrescǎtor. Folositi o implementare potrivitǎ a interfeţei Map, care sǎ permitǎ acest lucru, şi definiti un Comparator pentru stabilirea ordinii cheilor. (clasa internă statică)
4)	Definiţi în clasa MyMap metoda add(Student), ce va adǎuga un student în lista corespunzǎtoare mediei lui. Dacǎ, în prealabil, nu mai existǎ nici un student cu media respectivǎ (rotunjitǎ), atunci lista va fi creatǎ la cerere.  Observatie: Ce se intampla cand apelam metoda put mostenita de la dictionar?   „Favor Composition instead of Inheritance” – DISCUTIE CU STUDENTII....
5)	Adaugati câţiva studenţi.
6)	Definiti o metoda getEntries() care returneaza multimea intrarilor – Entry<Key, Value>
7)	Creati un dictionar de tipul MyMap si adaugati urmatorii studenti.
public static List<Student> getList(){
    List<Student> l=new ArrayList<Student>();
    l.add(new Student("1",9.7f));
    l.add(new Student("2",7.3f));
    l.add(new Student("3",6f));
    l.add(new Student("4",6.9f));
    l.add(new Student("5",9.5f));
    l.add(new Student("6",9.9f));
    return l;
}
8)	Iterati multimea intrarilor – Entry<Key, Value>  şi sortaţi alfabetic fiecare listǎ de studenţi.
