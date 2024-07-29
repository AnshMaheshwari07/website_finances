const express = require('express');
const bodyParser = require('body-parser');
const nodemailer = require('nodemailer');
const multer = require('multer');
const upload = multer();
const path = require('path');

const app = express();
const port = 3000;

// Middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// Serve static files (e.g., your HTML file)
app.use(express.static(path.join(__dirname, 'public')));

// Handle form submission
app.post('/career/submit-form', upload.single('resume'), (req, res) => {
    const { position, name, email, phone, message } = req.body;
    const resume = req.file;

    // Set up Nodemailer transporter
    const transporter = nodemailer.createTransport({
        service: 'gmail',
        auth: {
            user: '22ucs022@lnmiit.ac.in',
            pass: 'Ansh5678*'
        }
    });

    // Set up email options
    const mailOptions = {
        from: email,
        to: '22ucs022@lnmiit.ac.in',
        subject: `New Form Submission: ${name}`,
        text: `Position: ${position}\nName: ${name}\nEmail: ${email}\nPhone: ${phone}\nMessage: ${message}`,
        attachments: [
            {
                filename: resume.originalname,
                content: resume.buffer
            }
        ]
    };

    // Send email
    transporter.sendMail(mailOptions, (error, info) => {
        if (error) {
            return res.status(500).send(error.toString());
        }
        res.send('Form submitted successfully!');
    });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
