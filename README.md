# מטלה 1 , תכנות מערכות 2
### פרטים אישיים
חגי כהן , hagaycohen2@gmail.com , #####6180
# מבנה וחלוקה למחלקות
### מבט על
מתחילת המטלה ולאורך העבודה עליה תמיד חזרתי להוראה המרכזית
>ליצור מחלקה שמייצגת גרף ולממש אלגוריתמים על הגרפים

התכונות המתארות גרף והמטודות הישירות עליהן יושבות יחד במחלקה "גרף"

במקביל כתבתי מחלקת אלגוריתמים המחזיקה אלגוריתמים ופונקציות עזר המאבחנים את הגרפים מהבטים שונים

לצד מחלקות אלה הוספתי מקרי קצה לקובץ הטסטים כדי לוודא את נכונות האלגוריתמים 

אציין שהשתמשתי בקובץ הדמו המצורף רק בכדי לבדוק שהקוד שלי עובד ונתתי את הדגש שלי בעיקר במימושי המחלקות

מבנה המחלקות מפורט בהמשך.

## גרפים
### Graph.hpp

בקובץ זה מוגדר המבנה הבסיסי של גרף במחלקה `Graph` וחתימות המטודות שלו, 
 התכונות מוגדרות פרטיות והן : 

 מטריצת שכנויות, מספר הקודקודים , מספר הצלעות
 ```
    vector<vector<int>> matrix;
    size_t vertices;
    size_t edges;
```
כל המטודות מוגדרות ציבוריות ונגישות למשתמש והן:
```
 // constructor
    Graph();

    void loadGraph(vector<vector<int>> graph);
    void printGraph();
    vector<vector<int>> getMatrix();
    size_t getVertices();
```
על המטרה ואופן המימוש אפרט בחלק השני של הקובץ.

### Graph.cpp

קובץ זה מכיל את מימושי המטודות והבנאי של גרפים

קובץ זה אינו נגיש למשתמש חשוף רק לקובץ `Graph.hpp`

בנוסף נעשה שימוש גם ב `namespace std`

## אלגוריתמים
### Algorithms.hpp
בקובץ זה מוגדרים קבועים וכן מוגדרות שתי מחלקות, מחלקת `Algorithms` , והמחלקה `negativeCycleException`

#### המחלקה `Algorithms`

המחלקה`Algorithms` היא אוסף מטודות סטטיות אשר מנתחות גרפים מהבטים שונים ומחזירות מסקנות בהתאם

המחלקה מחולקת לאוסף מטודות סטטיות ציבוריות אשר כל אחת מיצגת "שאלה אחרת על גרף"

```
static int isConnected(Graph &graph);
    static string shortestPath(Graph &graph, size_t src, size_t dest);
    static string isContainsCycle(Graph &graph);
    static string isBipartite(Graph &graph);
    static string negativeCycle(Graph &graph);

```

ובנוסף אליהן אוסף מטודות סטטיות פרטיות המשמשות עבורן כפונקציות עזר 

```
static vector<vector<int>> DFS(Graph &graph, size_t src);
    static vector<int> DFS_visit(Graph &graph, size_t src, vector<int> &visited);
    static void DFS_parents_visit(Graph &graph, size_t src, vector<int> &visited, vector<int> &parents);              
    static vector<int> DFS_backEdge(Graph &graph, size_t src, vector<int> &visited, vector<int> &parents);
    static vector<int> BellmanFord(Graph &graph, size_t src);

```

כאמור מימוש האלגוריתמים ואופן השימוש בכל מתודה יפורט בחלקת השני של קובץ זה.

#### המחלקה `negativeCycleException`

מחלקה זו מייצגת שגיאה מיוחדת אשר זורקת פונקציית העזר `BellmanFord` 

השגיאה מכילה בתוכה את המעגל השלילי שזוהה.

### Algorithms.cpp

קובץ זה מכיל תחילה את המימושים של פונקציות העזר מ `Algorithms.hpp`

לאחר מכל בעזרת פונקציות אלה והמתודות במחלקה `Graph`  ממומשים כל האלגוריתמים הציבוריים של המחלקה

## שונות
### Test.cpp
קובץ בדיקות כפי שניתן עם המטלה שאיליו הוספתי עוד מקרי קצה

הקובץ מחולק לפי סוגי בדיקות בהתאם לאלגוריתמים השונים

המשכתי את הקובץ הקיים כדי "להרוויח" גם את הבדיקות הנתונות בנוסף לבדיקות שלי

### Makefile
עשיתי מספר שינויים בקובץ המייק שמטרתם לפצל בין הרצת תוכנית על אוסף גרפים (במקרה הזה demo)

לבין הרצת בדיקות על האלגוריתמים

פיצול זה נעשה מתוך חשיבה שהמחלקות שלי נועדו לשמש משתמשים אשר ירצו לקבל מסקנות לגבי הגרפים שלהם 

ולא נרצה שבכל שימוש במערכת האלגוריתמים יבדקו מחדש אלא נריץ בדיקה רק כשנבצע שינוי כלשהו במימוש

# מימושים והנחות
## הנחות כלליות
## גרפים
### Graph - בנאי
### loadGraph
### printGraph
### getMatrix , getVertices
## אלגוריתמים
### קבועים
### DFS
### DFS_visit
### DFS_parents_visit
### DFS_backEdge
### BellmanFord
### negativeCycleException
### isConnected
### shortestPath
### isContainsCycle
### isBipartite
### negativeCycle
## שונות
### tests
### Makefile
### demo - הערות

