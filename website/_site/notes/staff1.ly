\header {
    tagline = ##f
  }
\layout {
  \context {
    \Score
    \omit BarNumber
\omit BarLine
\omit SpanBar
\omit Stem
  }
}

\relative
{
\omit Staff.TimeSignature
\cadenzaOn
c' d e f g a b c d e f g a b c
}
\addlyrics {C D E F G A B C D E F G A B C}
