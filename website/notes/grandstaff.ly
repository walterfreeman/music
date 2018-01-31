#(set-default-paper-size "a4landscape")

\header {
    tagline = ##f 
  }
\new PianoStaff {
\cadenzaOn
%\omit BarLine
%\omit SpanBar
\omit PianoStaff.Stem
\omit PianoStaff.TimeSignature
  \autochange {
    c,, c, c cis d dis e f fis g gis a ais b c' cis' d' dis' e' f' fis' g' gis' a' ais' b' c'' cis'' d'' dis'' e'' f''
    fis'' g'' gis'' a'' ais'' b'' c'''

  }
}


