
// ds_data.h: include file for DVD Store actors and titles

// Names compiled by Dara Jaffe
// Cities compiled by Wes Brown
// Domain names compiled by Wes Brown
// Street names compiled by Wes Brown
// 200 actor/actress firstnames
// States moved from ds2_create_cust.c
// Countries moved from ds2_create_cust.c
// Days in month moved from ds2_create_cust.c
// Area Codes compiled by Wes Brown
char *actor_firstnames[] = 
            {
            "ADAM", "ADRIEN", "AL", "ALAN", "ALBERT", "ALEC", "ALICIA", "ANDY", "ANGELA", "ANGELINA", "ANJELICA", 
            "ANNE", "ANNETTE", "ANTHONY", "AUDREY", "BELA", "BEN", "BETTE", "BOB", "BRAD", "BRUCE", "BURT", "CAMERON", 
            "CANDICE", "CARMEN", "CARRIE", "CARY", "CATE", "CHARLES", "CHARLIZE", "CHARLTON", "CHEVY", "CHRIS", 
            "CHRISTIAN", "CHRISTOPHER", "CLARK", "CLINT", "CUBA", "DAN", "DANIEL", "DARYL", "DEBBIE", "DENNIS",
            "DENZEL", "DIANE", "DORIS", "DREW", "DUSTIN", "ED", "EDWARD", "ELIZABETH", "ELLEN", "ELVIS", "EMILY", 
            "ETHAN", "EWAN", "FARRAH", "FAY", "FRANCES", "FRANK", "FRED", "GARY", "GENE", "GEOFFREY", "GINA", "GLENN", 
            "GOLDIE", "GRACE", "GREG", "GREGORY", "GRETA", "GROUCHO", "GWYNETH", "HALLE", "HARRISON", "HARVEY", 
            "HELEN", "HENRY", "HILARY", "HUGH", "HUME", "HUMPHREY", "IAN", "INGRID", "JACK", "JADA", "JAMES", "JANE", 
            "JAYNE", "JEFF", "JENNIFER", "JEREMY", "JESSICA", "JIM", "JOAN", "JODIE", "JOE", "JOHN", "JOHNNY", "JON", 
            "JUDE", "JUDI", "JUDY", "JULIA", "JULIANNE", "JULIETTE", "KARL", "KATE", "KATHARINE", "KENNETH", "KEVIN", 
            "KIM", "KIRK", "KIRSTEN", "LANA", "LAURA", "LAUREN", "LAURENCE", "LEELEE", "LENA", "LEONARDO", "LIAM", 
            "LISA", "LIV", "LIZA", "LUCILLE", "MADELINE", "MAE", "MARILYN", "MARISA", "MARLENE", "MARLON", "MARY", 
            "MATT", "MATTHEW", "MEG", "MEL", "MENA", "MERYL", "MICHAEL", "MICHELLE", "MILLA", "MINNIE", "MIRA", 
            "MORGAN", "NATALIE", "NEVE", "NICK", "NICOLAS", "NICOLE", "OLYMPIA", "OPRAH", "ORLANDO", "PARKER", 
            "PAUL", "PEARL", "PENELOPE", "RALPH", "RAY", "REESE", "RENEE", "RICHARD", "RIP", "RITA", "RIVER", 
            "ROBERT", "ROBIN", "ROCK", "ROSIE", "RUBY", "RUSSELL", "SALLY", "SALMA", "SANDRA", "SCARLETT", "SEAN", 
            "SHIRLEY", "SIDNEY", "SIGOURNEY", "SISSY", "SOPHIA", "SPENCER", "STEVE", "SUSAN", "SYLVESTER", "THORA", 
            "TIM", "TOM", "UMA", "VAL", "VIVIEN", "WALTER", "WARREN", "WHOOPI", "WILL", "WILLEM", "WILLIAM", "WINONA", 
            "WOODY", "ZERO" 
            }; 

// 200 actor/actress lastnames
char *actor_lastnames[] = 
            {
            "AFFLECK", "AKROYD", "ALLEN", "ANISTON", "ASTAIRE", "BACALL", "BAILEY", "BALE", "BALL", "BARRYMORE", 
            "BASINGER", "BEATTY", "BENING", "BERGEN", "BERGMAN", "BERRY", "BIRCH", "BLANCHETT", "BLOOM", "BOGART", 
            "BOLGER", "BRANAGH", "BRANDO", "BRIDGES", "BRODY", "BULLOCK", "CAGE", "CAINE", "CAMPBELL", "CARREY", 
            "CHAPLIN", "CHASE", "CLOSE", "COOPER", "COSTNER", "CRAWFORD", "CRONYN", "CROWE", "CRUISE", "CRUZ", 
            "DAFOE", "DAMON", "DAVIS", "DAY", "DAY-LEWIS", "DEAN", "DEE", "DEGENERES", "DENCH", "DENIRO", 
            "DEPP", "DERN", "DIAZ", "DICAPRIO", "DIETRICH", "DOUGLAS", "DREYFUSS", "DRIVER", "DUKAKIS", "DUNST", 
            "EASTWOOD", "FAWCETT", "FIELD", "FIENNES", "FINNEY", "FISHER", "FONDA", "FORD", "FOSTER", "FREEMAN", 
            "GABLE", "GARBO", "GARCIA", "GARLAND", "GIBSON", "GOLDBERG", "GOODING", "GRANT", "GUINESS", "HACKMAN", 
            "HANNAH", "HARRIS", "HAWKE", "HAWN", "HAYEK", "HECHE", "HEPBURN", "HESTON", "HOFFMAN", "HOPE", 
            "HOPKINS", "HOPPER", "HORNE", "HUDSON", "HUNT", "HURT", "HUSTON", "IRONS", "JACKMAN", "JOHANSSON", 
            "JOLIE", "JOVOVICH", "KAHN", "KEATON", "KEITEL", "KELLY", "KIDMAN", "KILMER", "KINNEAR", "KUDROW", 
            "LANCASTER", "LANSBURY", "LAW", "LEIGH", "LEWIS", "LOLLOBRIGIDA", "LOREN", "LUGOSI", "MALDEN", "MANSFIELD", 
            "MARTIN", "MARX", "MATTHAU", "MCCONAUGHEY", "MCDORMAND", "MCGREGOR", "MCKELLEN", "MCQUEEN", "MINELLI", "MIRANDA", 
            "MONROE", "MOORE", "MOSTEL", "NEESON", "NEWMAN", "NICHOLSON", "NOLTE", "NORTON", "O'DONNELL", "OLIVIER", 
            "PACINO", "PALTROW", "PECK", "PENN", "PESCI", "PFEIFFER", "PHOENIX", "PINKETT", "PITT", "POITIER", 
            "POSEY", "PRESLEY", "REYNOLDS", "RICKMAN", "ROBBINS", "ROBERTS", "RUSH", "RUSSELL", "RYAN", "RYDER", 
            "SANDLER", "SARANDON", "SILVERSTONE", "SINATRA", "SMITH", "SOBIESKI", "SORVINO", "SPACEK", "STALLONE", "STREEP", 
            "SUVARI", "SWANK", "TANDY", "TAUTOU", "TAYLOR", "TEMPLE", "THERON", "THURMAN", "TOMEI", "TORN", 
            "TRACY", "TURNER", "TYLER", "VOIGHT", "WAHLBERG", "WALKEN", "WASHINGTON", "WATSON", "WAYNE", "WEAVER", 
            "WEST", "WILLIAMS", "WILLIS", "WILSON", "WINFREY", "WINSLET", "WITHERSPOON", "WOOD", "WRAY", "ZELLWEGER" 
            }; 

// 1000 movie title words
char *movie_titles[] = 
            {
            "ACADEMY", "ACE", "ADAPTATION", "AFFAIR", "AFRICAN", "AGENT", "AIRPLANE", "AIRPORT", "ALABAMA", "ALADDIN", 
            "ALAMO", "ALASKA", "ALI", "ALICE", "ALIEN", "ALLEY", "ALONE", "ALTER", "AMADEUS", "AMELIE", 
            "AMERICAN", "AMISTAD", "ANACONDA", "ANALYZE", "ANGELS", "ANNIE", "ANONYMOUS", "ANTHEM", "ANTITRUST", "ANYTHING", 
            "APACHE", "APOCALYPSE", "APOLLO", "ARABIA", "ARACHNOPHOBIA", "ARGONAUTS", "ARIZONA", "ARK", "ARMAGEDDON", "ARMY", 
            "ARSENIC", "ARTIST", "ATLANTIS", "ATTACKS", "ATTRACTION", "AUTUMN", "BABY", "BACKLASH", "BADMAN", "BAKED", 
            "BALLOON", "BALLROOM", "BANG", "BANGER", "BARBARELLA", "BAREFOOT", "BASIC", "BEACH", "BEAR", "BEAST", 
            "BEAUTY", "BED", "BEDAZZLED", "BEETHOVEN", "BEHAVIOR", "BENEATH", "BERETS", "BETRAYED", "BEVERLY", "BIKINI", 
            "BILKO", "BILL", "BINGO", "BIRCH", "BIRD", "BIRDCAGE", "BIRDS", "BLACKOUT", "BLADE", "BLANKET", 
            "BLINDNESS", "BLOOD", "BLUES", "BOILED", "BONNIE", "BOOGIE", "BOONDOCK", "BORN", "BORROWERS", "BOULEVARD", 
            "BOUND", "BOWFINGER", "BRANNIGAN", "BRAVEHEART", "BREAKFAST", "BREAKING", "BRIDE", "BRIGHT", "BRINGING", "BROOKLYN", 
            "BROTHERHOOD", "BUBBLE", "BUCKET", "BUGSY", "BULL", "BULWORTH", "BUNCH", "BUTCH", "BUTTERFLY", "CABIN", 
            "CADDYSHACK", "CALENDAR", "CALIFORNIA", "CAMELOT", "CAMPUS", "CANDIDATE", "CANDLES", "CANYON", "CAPER", "CARIBBEAN", 
            "CAROL", "CARRIE", "CASABLANCA", "CASPER", "CASSIDY", "CASUALTIES", "CAT", "CATCH", "CAUSE", "CELEBRITY", 
            "CENTER", "CHAINSAW", "CHAMBER", "CHAMPION", "CHANCE", "CHAPLIN", "CHARADE", "CHARIOTS", "CHASING", "CHEAPER", 
            "CHICAGO", "CHICKEN", "CHILL", "CHINATOWN", "CHISUM", "CHITTY", "CHOCOLAT", "CHOCOLATE", "CHRISTMAS", "CIDER", 
            "CINCINATTI", "CIRCUS", "CITIZEN", "CLASH", "CLEOPATRA", "CLERKS", "CLOCKWORK", "CLONES", "CLOSER", "CLUB", 
            "CLUE", "CLUELESS", "CLYDE", "COAST", "COLDBLOODED", "COLOR", "COMA", "COMANCHEROS", "COMFORTS", "COMMAND", 
            "COMMANDMENTS", "CONEHEADS", "CONFESSIONS", "CONFIDENTIAL", "CONFUSED", "CONGENIALITY", "CONNECTICUT", "CONNECTION",
            "CONQUERER", "CONSPIRACY", "CONTACT", "CONTROL", "CONVERSATION", "CORE", "COWBOY", "CRAFT", "CRANES", "CRAZY", 
            "CREATURES", "CREEPERS", "CROOKED", "CROSSING", "CROSSROADS", "CROW", "CROWDS", "CRUELTY", "CRUSADE", "CRYSTAL", 
            "CUPBOARD", "CURTAIN", "CYCLONE", "DADDY", "DAISY", "DALMATIONS", "DANCES", "DANCING", "DANGEROUS", "DARES", 
            "DARKNESS", "DARKO", "DARLING", "DARN", "DATE", "DAUGHTER", "DAWN", "DAY", "DAZED", "DECEIVER", "DEEP", "DEER", 
            "DELIVERANCE", "DESERT", "DESIRE", "DESPERATE", "DESTINATION", "DESTINY", "DETAILS", "DETECTIVE", "DEVIL", "DIARY", 
            "DINOSAUR", "DIRTY", "DISCIPLE", "DISTURBING", "DIVIDE", "DIVINE", "DIVORCE", "DOCTOR", "DOGMA", "DOLLS", 
            "DONNIE", "DOOM", "DOORS", "DORADO", "DOUBLE", "DOUBTFIRE", "DOWNHILL", "DOZEN", "DRACULA", "DRAGON", 
            "DRAGONFLY", "DREAM", "DRIFTER", "DRIVER", "DRIVING", "DROP", "DRUMLINE", "DRUMS", "DUCK", "DUDE", 
            "DUFFEL", "DUMBO", "DURHAM", "DWARFS", "DYING", "DYNAMITE", "EAGLES", "EARLY", "EARRING", "EARTH", 
            "EASY", "EDGE", "EFFECT", "EGG", "EGYPT", "ELEMENT", "ELEPHANT", "ELF", "ELIZABETH", "EMPIRE", 
            "ENCINO", "ENCOUNTERS", "ENDING", "ENEMY", "ENGLISH", "ENOUGH", "ENTRAPMENT", "ESCAPE", "EVE", "EVERYONE", "EVOLUTION", 
            "EXCITEMENT", "EXORCIST", "EXPECATIONS", "EXPENDABLE", "EXPRESS", "EXTRAORDINARY", "EYES", "FACTORY", "FALCON", 
            "FAMILY", "FANTASIA", "FANTASY", "FARGO", "FATAL", "FEATHERS", "FELLOWSHIP", "FERRIS", "FEUD", "FEVER", 
            "FICTION", "FIDDLER", "FIDELITY", "FIGHT", "FINDING", "FIRE", "FIREBALL", "FIREHOUSE", "FISH", "FLAMINGOS", 
            "FLASH", "FLATLINERS", "FLIGHT", "FLINTSTONES", "FLOATS", "FLYING", "FOOL", "FOREVER", "FORREST", "FORRESTER", 
            "FORWARD", "FRANKENSTEIN", "FREAKY", "FREDDY", "FREEDOM", "FRENCH", "FRIDA", "FRISCO", "FROGMEN", "FRONTIER", 
            "FROST", "FUGITIVE", "FULL", "FURY", "GABLES", "GALAXY", "GAMES", "GANDHI", "GANGS", "GARDEN", 
            "GASLIGHT", "GATHERING", "GENTLEMEN", "GHOST", "GHOSTBUSTERS", "GIANT", "GILBERT", "GILMORE", "GLADIATOR", "GLASS", 
            "GLEAMING", "GLORY", "GO", "GODFATHER", "GOLD", "GOLDFINGER", "GOLDMINE", "GONE", "GOODFELLAS", "GORGEOUS", 
            "GOSFORD", "GRACELAND", "GRADUATE", "GRAFFITI", "GRAIL", "GRAPES", "GREASE", "GREATEST", "GREEDY", "GREEK", 
            "GRINCH", "GRIT", "GROOVE", "GROSSE", "GROUNDHOG", "GUMP", "GUN", "GUNFIGHT", "GUNFIGHTER", "GUYS", 
            "HALF", "HALL", "HALLOWEEN", "HAMLET", "HANDICAP", "HANGING", "HANKY", "HANOVER", "HAPPINESS", "HARDLY", 
            "HAROLD", "HARPER", "HARRY", "HATE", "HAUNTED", "HAUNTING", "HAWK", "HEAD", "HEARTBREAKERS", "HEAVEN", 
            "HEAVENLY", "HEAVYWEIGHTS", "HEDWIG", "HELLFIGHTERS", "HIGH", "HIGHBALL", "HILLS", "HOBBIT", "HOCUS", "HOLES", 
            "HOLIDAY", "HOLLOW", "HOLLYWOOD", "HOLOCAUST", "HOLY", "HOME", "HOMEWARD", "HOMICIDE", "HONEY", "HOOK", 
            "HOOSIERS", "HOPE", "HORN", "HORROR", "HOTEL", "HOURS", "HOUSE", "HUMAN", "HUNCHBACK", "HUNGER", 
            "HUNTER", "HUNTING", "HURRICANE", "HUSTLER", "HYDE", "HYSTERICAL", "ICE", "IDAHO", "IDENTITY", "IDOLS", 
            "IGBY", "ILLUSION", "IMAGE", "IMPACT", "IMPOSSIBLE", "INCH", "INDEPENDENCE", "INDIAN", "INFORMER", "INNOCENT", 
            "INSECTS", "INSIDER", "INSTINCT", "INTENTIONS", "INTERVIEW", "INTOLERABLE", "INTRIGUE", "INVASION", "IRON", "ISHTAR", 
            "ISLAND", "ITALIAN", "JACKET", "JADE", "JAPANESE", "JASON", "JAWBREAKER", "JAWS", "JEDI", "JEEPERS", 
            "JEKYLL", "JEOPARDY", "JERICHO", "JERK", "JERSEY", "JET", "JINGLE", "JOON", "JUGGLER", "JUMANJI", 
            "JUMPING", "JUNGLE", "KANE", "KARATE", "KENTUCKIAN", "KICK", "KILL", "KILLER", "KING", "KISS", 
            "KISSING", "KNOCK", "KRAMER", "KWAI", "LABYRINTH", "LADY", "LADYBUGS", "LAMBS", "LANGUAGE", "LAWLESS", 
            "LAWRENCE", "LEAGUE", "LEATHERNECKS", "LEBOWSKI", "LEGALLY", "LEGEND", "LESSON", "LIAISONS", "LIBERTY", "LICENSE", 
            "LIES", "LIFE", "LIGHTS", "LION", "LOATHING", "LOCK", "LOLA", "LOLITA", "LONELY", "LORD", 
            "LOSE", "LOSER", "LOST", "LOUISIANA", "LOVE", "LOVELY", "LOVER", "LOVERBOY", "LUCK", "LUCKY", 
            "LUKE", "LUST", "MADIGAN", "MADISON", "MADNESS", "MADRE", "MAGIC", "MAGNIFICENT", "MAGNOLIA", "MAGUIRE", 
            "MAIDEN", "MAJESTIC", "MAKER", "MALKOVICH", "MALLRATS", "MALTESE", "MANCHURIAN", "MANNEQUIN", "MARRIED", "MARS", 
            "MASK", "MASKED", "MASSACRE", "MASSAGE", "MATRIX", "MAUDE", "MEET", "MEMENTO", "MENAGERIE", "MERMAID", 
            "METAL", "METROPOLIS", "MICROCOSMOS", "MIDNIGHT", "MIDSUMMER", "MIGHTY", "MILE", "MILLION", "MINDS", "MINE", 
            "MINORITY", "MIRACLE", "MISSION", "MIXED", "MOB", "MOCKINGBIRD", "MOD", "MODEL", "MODERN", "MONEY", 
            "MONSOON", "MONSTER", "MONTEREY", "MONTEZUMA", "MOON", "MOONSHINE", "MOONWALKER", "MOSQUITO", "MOTHER", "MOTIONS", 
            "MOULIN", "MOURNING", "MOVIE", "MULAN", "MULHOLLAND", "MUMMY", "MUPPET", "MURDER", "MUSCLE", "MUSIC", 
            "MUSKETEERS", "MUSSOLINI", "MYSTIC", "NAME", "NASH", "NATIONAL", "NATURAL", "NECKLACE", "NEIGHBORS", "NEMO", 
            "NETWORK", "NEWSIES", "NEWTON", "NIGHTMARE", "NONE", "NOON", "NORTH", "NORTHWEST", "NOTORIOUS", "NOTTING", 
            "NOVOCAINE", "NUTS", "OCTOBER", "ODDS", "OKLAHOMA", "OLEANDER", "OPEN", "OPERATION", "OPPOSITE", "OPUS", 
            "ORANGE", "ORDER", "ORIENT", "OSCAR", "OTHERS", "OUTBREAK", "OUTFIELD", "OUTLAW", "OZ", "PACIFIC", 
            "PACKER", "PAJAMA", "PANIC", "PANKY", "PANTHER", "PAPI", "PARADISE", "PARIS", "PARK", "PARTY", 
            "PAST", "PATHS", "PATIENT", "PATRIOT", "PATTON", "PAYCHECK", "PEACH", "PEAK", "PEARL", "PELICAN", 
            "PERDITION", "PERFECT", "PERSONAL", "PET", "PHANTOM", "PHILADELPHIA", "PIANIST", "PICKUP", "PILOT", "PINOCCHIO", 
            "PIRATES", "PITTSBURGH", "PITY", "PIZZA", "PLATOON", "PLUTO", "POCUS", "POLISH", "POLLOCK", "POND", 
            "POSEIDON", "POTLUCK", "POTTER", "PREJUDICE", "PRESIDENT", "PRIDE", "PRIMARY", "PRINCESS", "PRIVATE", "PRIX", 
            "PSYCHO", "PULP", "PUNK", "PURE", "PURPLE", "QUEEN", "QUEST", "QUILLS", "RACER", "RAGE", 
            "RAGING", "RAIDERS", "RAINBOW", "RANDOM", "RANGE", "REAP", "REAR", "REBEL", "RECORDS", "REDEMPTION", 
            "REDS", "REEF", "REIGN", "REMEMBER", "REQUIEM", "RESERVOIR", "RESURRECTION", "REUNION", "RIDER", "RIDGEMONT", 
            "RIGHT", "RINGS", "RIVER", "ROAD", "ROBBERS", "ROBBERY", "ROCK", "ROCKETEER", "ROCKY", "ROLLERCOASTER", 
            "ROMAN", "ROOF", "ROOM", "ROOTS", "ROSES", "ROUGE", "ROXANNE", "RUGRATS", "RULES", "RUN", 
            "RUNAWAY", "RUNNER", "RUSH", "RUSHMORE", "SABRINA", "SADDLE", "SAGEBRUSH", "SAINTS", "SALUTE", "SAMURAI", 
            "SANTA", "SASSY", "SATISFACTION", "SATURDAY", "SATURN", "SAVANNAH", "SCALAWAG", "SCARFACE", "SCHOOL", "SCISSORHANDS", 
            "SCORPION", "SEA", "SEABISCUIT", "SEARCHERS", "SEATTLE", "SECRET", "SECRETARY", "SECRETS", "SENSE", "SENSIBILITY", 
            "SEVEN", "SHAKESPEARE", "SHANE", "SHANGHAI", "SHAWSHANK", "SHEPHERD", "SHINING", "SHIP", "SHOCK", "SHOOTIST", 
            "SHOW", "SHREK", "SHRUNK", "SIDE", "SIEGE", "SIERRA", "SILENCE", "SILVERADO", "SIMON", "SINNERS", 
            "SISTER", "SKY", "SLACKER", "SLEEPING", "SLEEPLESS", "SLEEPY", "SLEUTH", "SLING", "SLIPPER", "SLUMS", 
            "SMILE", "SMOKING", "SMOOCHY", "SNATCH", "SNATCHERS", "SNOWMAN", "SOLDIERS", "SOMETHING", "SONG", "SONS", 
            "SORORITY", "SOUP", "SOUTH", "SPARTACUS", "SPEAKEASY", "SPEED", "SPICE", "SPIKING", "SPINAL", "SPIRIT", 
            "SPIRITED", "SPLASH", "SPLENDOR", "SPOILERS", "SPY", "SQUAD", "STAGE", "STAGECOACH", "STALLION", "STAMPEDE", 
            "STAR", "STATE", "STEEL", "STEERS", "STEPMOM", "STING", "STOCK", "STONE", "STORM", "STORY", 
            "STRAIGHT", "STRANGELOVE", "STRANGER", "STRANGERS", "STREAK", "STREETCAR", "STRICTLY", "SUBMARINE", "SUGAR", "SUICIDES", 
            "SUIT", "SUMMER", "SUN", "SUNDANCE", "SUNRISE", "SUNSET", "SUPER", "SUPERFLY", "SUSPECTS", "SWARM", 
            "SWEDEN", "SWEET", "SWEETHEARTS", "TADPOLE", "TALENTED", "TARZAN", "TAXI", "TEEN", "TELEGRAPH", "TELEMARK", 
            "TEMPLE", "TENENBAUMS", "TEQUILA", "TERMINATOR", "TEXAS", "THEORY", "THIEF", "THIN", "TIES", "TIGHTS", 
            "TIMBERLAND", "TITANIC", "TITANS", "TOMATOES", "TOMORROW", "TOOTSIE", "TORQUE", "TOURIST", "TOWERS", "TOWN", 
            "TRACY", "TRADING", "TRAFFIC", "TRAIN", "TRAINSPOTTING", "TRAMP", "TRANSLATION", "TRAP", "TREASURE", "TREATMENT", 
            "TRIP", "TROJAN", "TROOPERS", "TROUBLE", "TRUMAN", "TURN", "TUXEDO", "TWISTED", "TYCOON", "UNBREAKABLE", 
            "UNCUT", "UNDEFEATED", "UNFAITHFUL", "UNFORGIVEN", "UNITED", "UNTOUCHABLES", "UPRISING", "UPTOWN", "USUAL", "VACATION", 
            "VALENTINE", "VALLEY", "VAMPIRE", "VANILLA", "VANISHED", "VANISHING", "VARSITY", "VELVET", "VERTIGO", "VICTORY", 
            "VIDEOTAPE", "VIETNAM", "VILLAIN", "VIRGIN", "VIRGINIAN", "VIRTUAL", "VISION", "VOICE", "VOLCANO", "VOLUME", 
            "VOYAGE", "WAGON", "WAIT", "WAKE", "WALLS", "WANDA", "WAR", "WARDROBE", "WARLOCK", "WARS", 
            "WASH", "WASTELAND", "WATCH", "WATERFRONT", "WATERSHIP", "WEDDING", "WEEKEND", "WEREWOLF", "WEST", "WESTWARD", 
            "WHALE", "WHISPERER", "WIFE", "WILD", "WILLOW", "WIND", "WINDOW", "WISDOM", "WITCHES", "WIZARD", 
            "WOLVES", "WOMEN", "WON", "WONDERFUL", "WONDERLAND", "WONKA", "WORDS", "WORKER", "WORKING", "WORLD", 
            "WORST", "WRATH", "WRONG", "WYOMING", "YENTL", "YOUNG", "YOUTH", "ZHIVAGO", "ZOOLANDER", "ZORRO"
            };

// 16 categories
char *categories[] = 
            {
            "Action", "Animation", "Children", "Classics", "Comedy", "Documentary", "Drama", "Family", 
            "Foreign", "Games", "Horror", "Music", "New", "Sci-Fi", "Sports", "Travel" 
            };
//100 city names
char *customer_city_names[] = 
            {
            "New York","Los Angeles","Chicago","Houston","Philadelphia","Phoenix","San Antonio","San Diego","Dallas","San Jose","Jacksonville",
            "Indianapolis","Austin","San Francisco","Columbus","Fort Worth","Charlotte","Detroit","El Paso","Memphis","Boston","Seattle",
            "Denver","Baltimore","Washington","Nashville","Louisville","Milwaukee","Portland","Oklahoma City","Las Vegas","Albuquerque",
            "Tucson","Fresno","Sacramento","Long Beach","Kansas City","Mesa","Virginia Beach","Atlanta","Colorado Springs","Raleigh","Omaha",
            "Miami","Tulsa","Oakland","Cleveland","Minneapolis","Wichita","Arlington","New Orleans","Bakersfield","Tampa","Anaheim","Honolulu",
            "Aurora","Santa Ana","St. Louis","Riverside","Corpus Christi","Pittsburgh","Lexington","Stockton","Cincinnati","Anchorage","Saint Paul",
            "Toledo","Newark","Greensboro","Plano","Lincoln","Buffalo","Henderson","Fort Wayne","Jersey City","Chula Vista","Saint Petersburg",
            "Orlando","Norfolk","Laredo","Chandler","Madison","Lubbock","Durham","Winston–Salem","Garland","Glendale","Baton Rouge","Hialeah",
            "Reno","Chesapeake","Scottsdale","Irving","North Las Vegas","Fremont","Irvine","San Bernardino","Birmingham","Gilbert","Rochester"
            };
//200 domain names
char *customer_domain_names[] = 
            {
            "google.com","yahoo.com","t-online.de","amazon.com","blogspot.com","adobe.com","w3.org","youtube.com","wikipedia.org","wordpress.org",
            "facebook.com","microsoft.com","dot.tk","myspace.com","msn.com","macromedia.com","wordpress.com","geocities.com","miibeian.gov.cn",
            "flickr.com","digg.com","apple.com","aol.com","bbc.co.uk","sourceforge.net","cnn.com","icio.us","tripod.com","technorati.com",
            "live.com","ebay.com","feedburner.com","free.fr","nytimes.com","baidu.com","php.net","go.com","phpbb.com","about.com","qq.com",
            "blogger.com","mapquest.com","typepad.com","imdb.com","gmpg.org","paypal.com","freewebs.com","livejournal.com","netscape.com",
            "sina.com.cn","angelfire.com","joomla.org","reddit.com","apache.org","tinyurl.com","infospace.com","icq.com","photobucket.com",
            "washingtonpost.com","google.de","usatoday.com","guardian.co.uk","gnu.org","homestead.com","mac.com","verizon.net","nih.gov",
            "reuters.com","imageshack.us","mysql.com","mozilla.org","rambler.ru","mit.edu","kolmic.com","creativecommons.org","yahoo.co.jp",
            "nasa.gov","weather.com","stanford.edu","com.com","cnet.com","wsj.com","berkeley.edu","narod.ru","bloglines.com","archive.org",
            "harvard.edu","mail.ru","ibm.com","google.co.uk","gc.ca","altavista.com","fc2.com","kiev.ua","spb.ru","searchnut.com","wired.com",
            "mozilla.com","latimes.com","forbes.com","dmoz.org","cjb.net","ca.gov","amazon.co.uk","lycos.com","telegraph.co.uk","boston.com",
            "timesonline.co.uk","amazon.de","hp.com","sun.com","noaa.gov","cdc.gov","pbs.org","sfgate.com","deviantart.com","loc.gov",
            "googlepages.com","altervista.org","slashdot.org","foxnews.com","opera.com","lycos.co.uk","cornell.edu","uk.com","businessweek.com",
            "time.com","real.com","infoseek.co.jp","on.ca","wunderground.com","umich.edu","nwsource.com","qc.ca","earthlink.net","cafepress.com",
            "nifty.com","ign.com","uiuc.edu","npr.org","download.com","whitehouse.gov","nationalgeographic.com","bc.ca","utexas.edu","washington.edu",
            "cbsnews.com","de.vu","lycos.fr","ifrance.com","comcast.net","zdnet.com","news.com.au","columbia.edu","dyndns.org","ca.us","bloomberg.com",
            "bizjournals.com","discovery.com","xanga.com","wisc.edu","epa.gov","virginia.edu","state.gov","cbc.ca","upenn.edu","yale.edu","blogs.com",
            "house.gov","ucla.edu","fda.gov","demon.co.uk","ftc.gov","nps.gov","tx.us","usda.gov","ed.gov","umn.edu","psu.edu","fortunecity.com",
            "irs.gov","iht.com","Howstuffworks.com","ww7.be","europa.eu.int","cmu.edu","msu.edu","bravenet.com","senate.gov","register.com",
            "ufl.edu","ucsd.edu","indiana.edu","att.net","findarticles.com","ny.us","xs4all.nl","wanadoo.fr","webring.com","adobe.de"
            };
char *states[] = 
			{
			"AK", "AL", "AR", "AZ", "CA", "CO", "CT", "DC", "DE", "FL", "GA", "HI", "IA", "ID", "IL", "IN", 
			"KS", "KY", "LA", "MA", "MD", "ME", "MI", "MN", "MO", "MS", "MT", "NC", "ND", "NE", "NH", "NJ",
			"NM", "NV", "NY", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VA", "VT", "WA",
			"WI", "WV", "WY"	
			};

char *countries[] = 
			{
			"Australia", "Canada", "Chile", "China", "France", "Germany", "Japan", "Russia", "South Africa", "UK"
			};

int i_days_in_month[] = 
			{
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
			};

// 322 street names
char *street_names[] = 
            {
            "Main Street","Church Street","Main Street North","High Street","Elm Street","Main Street South","Chestnut Street","Washington Street",
            "Main Street West","Walnut Street","Maple Street","2nd Street","Broad Street","Center Street","Main Street East","Maple Avenue",
            "South Street","Park Avenue","Water Street","Pine Street","Market Street","North Street","School Street","Union Street","Oak Street",
            "Spring Street","River Road","Court Street","Prospect Street","Cedar Street","Front Street","3rd Street","Park Street","Washington Avenue",
            "Cherry Street","Franklin Street","Central Avenue","Highland Avenue","Spruce Street","1st Street","Bridge Street","Jefferson Street",
            "West Street","Pleasant Street","State Street","4th Street","East Street","Hill Street","Jackson Street","Locust Street","Ridge Road",
            "Adams Street","Church Road","Dogwood Drive","Elizabeth Street","Green Street","Lincoln Avenue","Madison Street","Mill Street",
            "Pennsylvania Avenue","Route 1","4th Street West","3rd Street West","5th Street","Lincoln Street","Park Place","Winding Way",
            "2nd Avenue","Hillside Avenue","Liberty Street","Madison Avenue","Meadow Lane","Pearl Street","River Street","Route 30","Academy Street",
            "Broadway","Cherry Lane","Grove Street","Hickory Lane","Jefferson Avenue","New Street","Railroad Street","Route 6","Vine Street",
            "2nd Street West","5th Avenue","Beech Street","Monroe Street","Sunset Drive","Valley Road","11th Street","12th Street","3rd Avenue",
            "Arch Street","Colonial Drive","Holly Drive","Oak Lane","Route 32","Woodland Drive","1st Avenue","5th Street North","6th Street",
            "Clinton Street","Fairway Drive","Heather Lane","Laurel Lane","Mill Road","Myrtle Avenue","Summit Avenue","Valley View Drive",
            "Willow Street","4th Avenue","4th Street North","5th Street West","Canal Street","Canterbury Court","Creek Road","Delaware Avenue",
            "Division Street","Dogwood Lane","Durham Road","Fairview Avenue","Front Street North","Garden Street","Mulberry Street","Poplar Street",
            "Prospect Avenue","Railroad Avenue","Riverside Drive","Route 10","10th Street","13th Street","6th Street West","7th Street",
            "Buckingham Drive","Cedar Lane","Cottage Street","Devon Road","Elm Avenue","Franklin Court","Hamilton Street","Harrison Street",
            "Highland Drive","John Street","Lafayette Avenue","Lake Street","Laurel Street","Olive Street","Orange Street","Ridge Avenue",
            "Route 11","Route 29","Route 4","Smith Street","2nd Street East","5th Street South","6th Avenue","6th Street North","7th Avenue",
            "Aspen Court","Bank Street","Beechwood Drive","Belmont Avenue","Brookside Drive","Cambridge Court","Chapel Street","Charles Street",
            "Circle Drive","College Street","Colonial Avenue","Creekside Drive","Crescent Street","Cypress Court","Essex Court","Forest Drive",
            "Franklin Avenue","Garfield Avenue","George Street","Glenwood Avenue","Hillside Drive","James Street","King Street","Laurel Drive",
            "Magnolia Drive","Oxford Court","Route 20","Route 7","Surrey Lane","Tanglewood Drive","Virginia Avenue","Walnut Avenue","Williams Street",
            "Windsor Drive","Woodland Avenue","York Road","3rd Street East","9th Street","Carriage Drive","Chestnut Avenue","Church Street North",
            "Cobblestone Court","College Avenue","Elmwood Avenue","Front Street South","Grant Avenue","Grove Avenue","Hawthorne Lane","Henry Street",
            "Heritage Drive","Hillcrest Avenue","Hilltop Road","Jefferson Court","Lilac Lane","Linden Street","Locust Lane","Oak Avenue","Orchard Street",
            "Park Drive","Penn Street","Primrose Lane","Route 100","Route 202","Route 44","Street Road","Taylor Street","Wall Street","2nd Street North",
            "3rd Street North","Atlantic Avenue","Briarwood Drive","Buttonwood Drive","Cardinal Drive","Catherine Street","Cedar Avenue","Cedar Court",
            "Clark Street","Cooper Street","Deerfield Drive","Devonshire Drive","Durham Court","Eagle Road","Fawn Lane","Fieldstone Drive","Forest Street",
            "Fulton Street","Harrison Avenue","Lake Avenue","Lantern Lane","Magnolia Court","Mechanic Street","Mulberry Court","Pheasant Run","Redwood Drive",
            "Route 41","Route 70","Route 9","Sheffield Drive","Sherwood Drive","Strawberry Lane","Summit Street","Sunset Avenue","Sycamore Drive",
            "Warren Avenue","Windsor Court","Woodland Road","14th Street","8th Avenue","8th Street","8th Street South","Andover Court","Ashley Court",
            "Bridle Lane","Brook Lane","Cambridge Road","Canterbury Drive","Cemetery Road","Columbia Street","Country Club Road","Depot Street",
            "Edgewood Drive","Euclid Avenue","Evergreen Lane","Fairview Road","Glenwood Drive","Grand Avenue","Grant Street","Heather Court",
            "Hickory Street","Holly Court","Ivy Court","Jackson Avenue","Lafayette Street","Lakeview Drive","Lawrence Street","Linda Lane","Madison Court",
            "Magnolia Avenue","Maple Lane","Mulberry Lane","Old York Road","Orchard Avenue","Oxford Road","Pin Oak Drive","Queen Street","Ridge Street",
            "Rosewood Drive","Route 17","Route 27","Schoolhouse Lane","Spruce Avenue","Summer Street","Sycamore Lane","Valley Drive","Valley View Road",
            "Victoria Court","Warren Street","West Avenue","Westminster Drive","Willow Drive","Wood Street","York Street"
            };

//293 US area codes			
int us_area_codes[] ={
		201,202,203,204,205,206,207,208,209,210,212,213,214,215,216,217,218,219,225,228,229,231,234,240,242,246,248,250,252,253,254,256,
		262,264,267,268,270,281,284,301,302,303,304,305,306,307,308,309,310,312,313,314,315,316,317,318,319,320,321,323,330,334,336,337,
		340,345,347,352,360,361,385,401,402,403,404,405,406,407,408,409,410,412,413,414,415,416,417,418,419,423,425,435,440,441,443,450,
		456,469,473,478,480,484,500,501,502,503,504,505,506,507,508,509,510,512,513,514,515,516,517,518,519,520,530,540,541,559,561,562,
		570,571,573,580,600,601,602,603,604,605,606,607,608,609,610,612,613,614,615,616,617,618,619,623,626,630,631,636,641,646,647,649,
		650,651,660,661,662,664,670,671,678,682,700,701,702,703,704,705,706,707,708,709,710,712,713,714,715,716,717,718,719,720,724,727,
		732,734,740,757,758,760,763,765,767,770,773,775,780,781,784,785,786,787,800,801,802,803,804,805,806,807,808,809,810,812,813,814,
		815,816,817,818,819,828,830,831,832,843,845,847,850,856,858,859,860,863,864,865,866,867,867,867,868,869,870,876,877,880,881,882,
		888,900,901,902,902,903,904,905,906,907,908,909,910,912,913,914,915,916,917,918,919,920,925,931,936,937,940,941,949,952,954,956,
		970,971,972,973,978,979
		};