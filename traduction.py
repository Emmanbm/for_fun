from deep_translator import GoogleTranslator
from tkinter import *
from tkinter import ttk

root = Tk()
root.title('Emman Translate')
root.positionfrom('user')
root.geometry('800x300')

src = ''
dest = ''
text = ''

def comboAction(event):
    global src
    global dest
    src = dict_lang[str(combo_src.get().lower())]
    dest = dict_lang[str(combo_dest.get().lower())]

def traduction(event):
    global text
    text = T1.get('1.0', END)
    translated = GoogleTranslator(source=src, target=dest).translate(text)
    T2.insert(END, translated+'\n')

dict_lang = {'détecter la langue': 'auto', 'afrikaans': 'af', 'albanian': 'sq', 'amharic': 'am', 'arabic': 'ar', 'armenian': 'hy',
             'azerbaijani': 'az', 'basque': 'eu', 'belarusian': 'be', 'bengali': 'bn', 'bosnian': 'bs', 'bulgarian': 'bg', 'catalan': 'ca',
             'cebuano': 'ceb', 'chichewa': 'ny', 'chinese (simplified)': 'zh-CN', 'chinese (traditional)': 'zh-TW', 'corsican': 'co', 'croatian': 'hr',
             'czech': 'cs', 'danish': 'da', 'dutch': 'nl', 'english': 'en', 'esperanto': 'eo', 'estonian': 'et', 'filipino': 'tl', 'finnish': 'fi',
             'french': 'fr', 'frisian': 'fy', 'galician': 'gl', 'georgian': 'ka', 'german': 'de', 'greek': 'el', 'gujarati': 'gu',
             'haitian creole': 'ht', 'hausa': 'ha', 'hawaiian': 'haw', 'hebrew': 'iw', 'hindi': 'hi', 'hmong': 'hmn', 'hungarian': 'hu', 'icelandic': 'is',
             'igbo': 'ig', 'indonesian': 'id', 'irish': 'ga', 'italian': 'it', 'japanese': 'ja', 'javanese': 'jw', 'kannada': 'kn', 'kazakh': 'kk',
             'khmer': 'km', 'kinyarwanda': 'rw', 'korean': 'ko', 'kurdish': 'ku', 'kyrgyz': 'ky', 'lao': 'lo', 'latin': 'la', 'latvian': 'lv',
             'lithuanian': 'lt', 'luxembourgish': 'lb', 'macedonian': 'mk', 'malagasy': 'mg', 'malay': 'ms', 'malayalam': 'ml', 'maltese': 'mt',
             'maori': 'mi', 'marathi': 'mr', 'mongolian': 'mn', 'myanmar': 'my', 'nepali': 'ne', 'norwegian': 'no', 'odia': 'or', 'pashto': 'ps',
             'persian': 'fa', 'polish': 'pl', 'portuguese': 'pt', 'punjabi': 'pa', 'romanian': 'ro', 'russian': 'ru', 'samoan': 'sm',
             'scots gaelic': 'gd', 'serbian': 'sr', 'sesotho': 'st', 'shona': 'sn', 'sindhi': 'sd', 'sinhala': 'si', 'slovak': 'sk', 'slovenian': 'sl',
             'somali': 'so', 'spanish': 'es', 'sundanese': 'su', 'swahili': 'sw', 'swedish': 'sv', 'tajik': 'tg', 'tamil': 'ta', 'tatar': 'tt',
             'telugu': 'te', 'thai': 'th', 'turkish': 'tr', 'turkmen': 'tk', 'ukrainian': 'uk', 'urdu': 'ur', 'uyghur': 'ug', 'uzbek': 'uz',
             'vietnamese': 'vi', 'welsh': 'cy', 'xhosa': 'xh', 'yiddish': 'yi', 'yoruba': 'yo', 'zulu': 'zu'}

list_lang = [i.capitalize() for i in dict_lang]

lang_source_label = Label(root, text= 'Langue source')
lang_source_label.place(x=20, y = 50)

lang_dest_label = Label(root, text='Langue de destination')
lang_dest_label.place(x=430, y=50)

combo_src = ttk.Combobox(root, values=list_lang)
combo_src.place(x=200, y=80)
combo_src.current(0)
combo_src.configure(font=('Calibri', 10))
combo_src.bind('<<ComboboxSelected>>', comboAction)

combo_dest = ttk.Combobox(root, values=list_lang[1:])
combo_dest.place(x=600, y=80)
combo_dest.current(int(list_lang.index('English'))-1)
combo_dest.configure(font=('Calibri', 10))
combo_dest.bind('<<ComboboxSelected>>', comboAction)

T1 = Text(root)
T1.place(x=20, y=120, width=400, height=150)
T1.configure(font=('Calibri', 15))
T1.bind('<Return>', traduction)

T2 = Text(root)
T2.place(x=430, y=120, width=350, height=150)
T2.configure(font=('Calibri', 15))

root.mainloop()
