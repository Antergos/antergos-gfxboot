% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
%
% Language selection dialog.
%
% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Some global vars.
%

% fallback if there is no "languages"
/lang.items [ "en_US" ] def
/lang.names [ "English (US)" ] def
% /lang.displayed false def

/.la.locale 0 def
/.la.keymap 1 def
/.la.rtl    2 def
/.la.name   3 def
/.la.layout 4 def

/lang.defaultnames [
  [ "af_ZA" "us"                   false "Afrikaans"                                     "us" ] % Afrikaans
  [ "ar_EG" "arabic"               true  "\ufef2\ufe91\ufeae\ufecb"                     "ara" ] % Arabic
  [ "ast_ES" "es"                  false "Asturianu"                                     "es" ] % Asturian
  [ "bg_BG" "us"                   false "Български"                                     "bg" ] % Bulgarian
  [ "bn_BD" "us"                   false "\u09ac\u09be\u0982\u09b2\u09be"                "in" ] % Bengali
  [ "bs_BA" "us"                   false "Bosanski"                                      "bd" ] % Bosnian
  [ "ca_ES" "es"                   false "Català"                                        "es" ] % Catalan
  [ "cs_CZ" "cz-us-qwertz"         false "Čeština"                                       "cz" ] % Czech
  [ "cy_GB" "us"                   false "Cymraeg"                                       "gb" ] % Welsh
  [ "da_DK" "dk"                   false "Dansk"                                         "dk" ] % Danish
  [ "de_BE" "be-latin1"            false "Deutsch (Belgien)"                             "be" ] % Germal (Belgium)
  [ "de_DE" "de-latin1-nodeadkeys" false "Deutsch"                                       "de" ] % German
  [ "el_GR" "gr"                   false "Ελληνικά"                                      "gr" ] % Greek
  [ "en_GB" "uk"                   false "English (UK)"                                  "gb" ] % English
  [ "en_US" "us"                   false "English (US)"                                  "us" ] % English
  [ "es_ES" "es"                   false "Español"                                       "es" ] % Spanish
  [ "et_EE" "et"                   false "Eesti"                                         "ee" ] % Estonian
  [ "fa_IR" "us"                   true  "\ufbfd\ufeb4\u0631\ufe8e\ufed3"                "us" ] % Farsi
  [ "fi_FI" "fi-latin1"            false "Suomi"                                         "fi" ] % Finnish
  [ "fr_FR" "fr-latin1"            false "Français"                                      "fr" ] % French
  [ "fr_BE" "be-latin1"            false "Français (Belgique)"                           "be" ] % French (Belgium)
  [ "gl_ES" "es"                   false "Galego"                                        "es" ] % Galician
  [ "ka_GE" "us"                   false "ქართული"                                       "us" ] % Kartuli
  [ "gu_IN" "us"                   false "\u0a97\u0ac1\u0a9c\u0ab0\u0abe\u0aa4\u0ac0"    "in" ] % Gujarati
  [ "he_IL" "us"                   false "תירבע"                                         "il" ] % Hebrew
  [ "hi_IN" "us"                   false "\u0939\u093f\u0902\u0926\u0940"                "in" ] % Hindi
  [ "hr_HR" "croat"                false "Hrvatski"                                      "hr" ] % Croatian
  [ "hu_HU" "hu"                   false "Magyar"                                        "hu" ] % Hungarian
  [ "id_ID" "us"                   false "Bahasa Indonesia"                              "us" ] % Indonesian
  [ "it_IT" "it"                   false "Italiano"                                      "it" ] % Italian
  [ "ja_JP" "jp106"                false "日本語"                                         "jp" ] % Japanese
  [ "jv_ID" "us"                   false "Basa Jawa"                                     "us" ] % Javanese
  [ "km_KH" "khmer"                false "Khmer"                                         "kh" ] % Khmer
  [ "ko_KR" "korean"               false "한글"                                           "kr" ] % Korean
  [ "ky_KG" "us"                   false "Кыргызча"                                      "kg" ] % Kirghiz
  [ "lo_LA" "us"                   false "\u0e9e\u0eb2\u0eaa\u0eb2\u0ea5\u0eb2\u0ea7"    "la" ] % Lao
  [ "lt_LT" "lt.baltic"            false "Lietuvių"                                      "lt" ] % Lithuanian
  [ "mk_MK" "us"                   false "Македонски"                                    "mk" ] % Macedonian
  [ "mr_IN" "us"                   false "\u092e\u0930\u093e\u0920\u0940"                "in" ] % Marathi
  [ "nb_NO" "no-latin1"            false "Norsk"                                         "no" ] % Norwegian
  [ "nl_BE" "be-latin1"            false "Nederlands (België)"                           "be" ] % Dutch (Belgium)
  [ "nl_NL" "us"                   false "Nederlands"                                    "nl" ] % Dutch
  [ "nn_NO" "no-latin1"            false "Nynorsk"                                       "no" ] % Nynorsk
  [ "pa_IN" "us"                   false "\u0a2a\u0a70\u0a1c\u0a3e\u0a2c\u0a40"          "in" ] % Punjabi
  [ "pl_PL" "Pl02"                 false "Polski"                                        "pl" ] % Polish
  [ "pt_BR" "br-abnt2"             false "Português (Brasil)"                            "br" ] % Portuguese (Brazilian)
  [ "pt_PT" "pt-latin1"            false "Português"                                     "pt" ] % Portuguese
  [ "ro_RO" "us"                   false "Română"                                        "ro" ] % Romanian
  [ "ru_RU" "ruwin_alt-UTF-8"      false "Русский"                                       "ru" ] % Russian
  [ "si_LK" "us"                   false "\u0dc3\u0dd2\u0d82\u0dc4\u0dbd"                "lk" ] % Sinhala
  [ "sk_SK" "sk-qwertz"            false "Slovenčina"                                    "sk" ] % Slovak
  [ "sl_SI" "slovene"              false "Slovenščina"                                   "si" ] % Slovenian
  [ "sr_RS" "sr-cy"                false "Srpski"                                        "rs" ] % Serbian
  [ "sv_SE" "sv-latin1"            false "Svenska"                                       "se" ] % Swedish
  [ "ta_IN" "us"                   false "\u0ba4\u0bae\u0bbf\u0bb4\u0bcd"                "in" ] % Tamil
  [ "tg_TJ" "tj"                   false "тоҷикӣ"                                        "tj" ] % Tadjik
  [ "th_TH" "us"                   false "\u0e20\u0e32\u0e29\u0e32\u0e44\u0e17\u0e22"    "th" ] % Thai
  [ "tr_TR" "trq"                  false "Türkçe"                                        "tr" ] % Turkish
  [ "uk_UA" "ua"                   false "Українська"                                    "ua" ] % Ukrainian
  [ "vi_VN" "us"                   false "Tiếng Việt"                                    "vn" ] % Vietnamese
  [ "wa_BE" "be-latin1"            false "Walon"                                         "be" ] % Walloon
  [ "xh_ZA" "us"                   false "isiXhosa"                                      "us" ] % Xhosa
  [ "zh_CN" "us"                   false "简体中文"                                        "us" ] % Simplified Chinese
  [ "zh_TW" "us"                   false "繁體中文 (台灣)"                                  "us" ] % Traditional Chinese
  [ "zu_ZA" "us"                   false "isiZulu"                                       "us" ] % Zulu
] def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Get language property.
%
% Returns .undef if not found.
%
% ( locale prop ) ==> ( obj )
%
/lang.getprop {
  lang.defaultnames {
    dup .la.locale get 3 index eq { exch get exch pop return } { pop } ifelse
  } forall

  % try a loose match
  lang.defaultnames {
    dup .la.locale get 3 index locale.cmp { exch get exch pop return } { pop } ifelse
  } forall

  pop pop .undef
} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Get language name.
%
% Returns locale if not found.
%
% ( locale ) ==> ( name )
%
/lang.getdefname {
  dup
  .la.name lang.getprop
  dup .undef ne { exch } if
  pop
} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Check for rtl.
%
% ( locale ) ==> ( bool )
%
/lang.getrtl {
  .la.rtl lang.getprop
  dup .undef eq { pop false } if
} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Parse "languages" file.
%
% ( ) ==> ( )
%
/lang.parsedata {
  /lang.default 0 def

  "languages" findfile dup { /lang.data exch def } { pop return } ifelse

  /la.tmp.datalen lang.data length def
  /la.tmp.str lang.data cvs def
 
  la.tmp.datalen 0 eq { return } if
  la.tmp.str la.tmp.datalen 1 sub get '\n' ne { return } if

  '\n' seteotchar

  /lang.items [

    /la.tmp.len 0 def
    /la.tmp.cnt 0 def
    {
      la.tmp.str la.tmp.len add strdup
      dup dup length 0 put
      /la.tmp.len over length 1 add la.tmp.len add def

      dup 0 get '*' eq { 1 add /lang.default la.tmp.cnt def } if

      la.tmp.len la.tmp.datalen ge { exit } if

      /la.tmp.cnt inc
    } loop

  ] def

  ' ' seteotchar

  /lang.names [

    lang.items {

      dup dup length add

      dup 0 get {
        dup 0 0 put 1 add
        exch pop
      } {
        pop lang.getdefname
      } ifelse

    } forall

    keymap.submenu {
      /lang.submenu.keyboard
    } if

  ] def

  /lang.submenu.idx keymap.submenu { lang.names length 1 sub } { -1 } ifelse def

  0 seteotchar

} def


/lang.submenu.keyboard.buf 64 string def
/lang.submenu.keyboard {
  /txt_keyboard exec "\x09\x09%s" lang.submenu.keyboard.buf sprintf
  lang.submenu.keyboard.buf
} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Build language list.
%
% ( ) ==> ( )
%
/lang.init {
  /xmenu.lang .xm_size array def
  /xmenu xmenu.lang def

  lang.parsedata

  xmenu .xm_current lang.default put
  xmenu .xm_list lang.names put

  xmenu .xm_title /txt_language put

  % make menu smaller if there are more than 19 language entries
  %lang.items length 19 gt {
  %  xmenu .xm_vspace 2 put
  %} if

  % start with current lang

  /la.tmp.cnt 0 def
  lang.items {
    config.lang locale.cmp { xmenu .xm_current la.tmp.cnt put exit } if
    /la.tmp.cnt inc
  } forall

  /la.tmp.cnt 0 def
  lang.items {
    config.lang eq { xmenu .xm_current la.tmp.cnt put exit } if
    /la.tmp.cnt inc
  } forall

  % needed in case menu is only attached to lang menu
  keymap.init
} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Update language.
%
% ( ) ==> ( )
%
/lang.update {
  /xmenu xmenu.lang def

  xmenu .xm_current get lang.submenu.idx eq {
    xmenu .xm_current over .xm_last get put
    panel.keymap
  } {
    lang.items xmenu .xm_current get get
    dup
    setlang { /window.action actRedraw def } if
    getkeymapfromlocale setkeymap
    keymap.setdefault
  } ifelse

} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Show language menu.
%
% ( ) => ( )
%
/panel.lang {
  "keytable" help.setcontext

  window.xmenu
  dup .xmenu xmenu.lang put
  dup .xmenu.update /lang.update put
  dup window.init
      window.show
} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Return width of panel entry.
%
% ( ) => ( width )
%
/panel.lang.width {
  /xmenu xmenu.lang def

  pmenu.width
} def


% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
% Redraw panel entry.
%
% ( panel ) => ( )
%
/panel.lang.update {
  /xmenu xmenu.lang def

  pmenu.panel.update

  xmenu.keymap .xm_panel_x xmenu.lang .xm_panel_x get put
} def


