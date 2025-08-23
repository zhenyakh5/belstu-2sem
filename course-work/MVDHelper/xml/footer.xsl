<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" indent="yes"/>

    <xsl:template match="/">
        <html>
            <head>
                <style>
                    body {
                        background: #000;
                    }

                    h3 {
                        color: #FFF;
                        text-align: center;
                        font-family: Arial;
                        font-style: normal;
                        font-weight: 400;
                        line-height: normal;
                    }
                </style>
            </head>
            <body>
                <h3>Курсовую работу на тему "<xsl:value-of select="authorInfo/topic"/>" выполнил студент <xsl:value-of select="authorInfo/course"/> курса <xsl:value-of select="authorInfo/group"/> группы факультета <xsl:value-of select="authorInfo/faculty"/> специальности <xsl:value-of select="authorInfo/spec"/><xsl:value-of select="authorInfo/surname"/><xsl:value-of select="authorInfo/name"/></h3>
            </body>
        </html>
    </xsl:template>

</xsl:stylesheet>
